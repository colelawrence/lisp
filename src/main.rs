use std::fmt::Write;
use std::process::exit;
use std::rc::Rc;
use tree_sitter::{Language, Parser};

extern "C" {
    fn tree_sitter_lisp() -> Language;
}

const LISP_EXAMPLE: &'static str = r#"(+ 2 3 (- 20 10))"#;

#[derive(Debug)]
struct Span<T> {
    node: T,
    file: u16,
    start: usize,
    end: usize,
}

impl<T> Span<T> {
    fn from_node(file: u16, node: &tree_sitter::Node, value: T) -> Self {
        Self {
            end: node.end_byte(),
            start: node.start_byte(),
            file,
            node: value,
        }
    }
}

#[derive(Debug)]
enum Node {
    Call(Span<Call>),
    List(Span<List>),
    Number(Span<usize>),
    String(Span<String>),
    Identifier(Span<String>),
}

#[derive(Debug)]
struct Call {
    name: Span<String>,
    params: Vec<Rc<Span<Node>>>,
}

#[derive(Debug)]
struct List {
    items: Vec<Rc<Span<Node>>>,
}

#[derive(Debug)]
struct SourceFile {
    file: u16,
    definitions: Vec<Span<Call>>,
}

fn main() {
    let mut parser = Parser::new();

    let language = unsafe { tree_sitter_lisp() };
    parser.set_language(language).unwrap();

    let tree = parser.parse(LISP_EXAMPLE, None).unwrap();

    match parse_source_file(LISP_EXAMPLE.to_string(), &tree.root_node()) {
        Ok(ast) => println!("TODO: Implement interpreter\n{:?}", ast),
        Err(message) => panic!("ERROR: {:?}", message),
    }
}

type ParseResult<T> = Result<Span<T>, Span<String>>;

struct SourceContext {
    file_id: u16,
    source: String,
    errors: Vec<Span<String>>,
}

fn parse_source_file(source: String, root_node: &tree_sitter::Node) -> ParseResult<SourceFile> {
    let file_id = 0u16;
    let mut source = SourceContext {
        source,
        file_id,
        errors: vec![],
    };
    let res = source.parse(root_node);
    if source.errors.len() > 0 {
        let mut message = String::new();
        for err in source.errors {
            write!(
                &mut message,
                "{}:\n{}\n",
                &err.node,
                &source.source[err.start..err.end]
            )
            .expect("Error occurred while trying to write in String");
        }
        eprintln!("ERRORS: {}", message);
        exit(1)
    } else {
        res
    }
}

impl SourceContext {
    fn span<T>(&self, node: &tree_sitter::Node, value: T) -> Span<T> {
        Span::from_node(self.file_id, node, value)
    }

    fn ok<T>(&self, node: &tree_sitter::Node, value: T) -> ParseResult<T> {
        Ok(self.span(node, value))
    }

    fn err<T, S: Into<String>>(&self, node: &tree_sitter::Node, value: S) -> ParseResult<T> {
        Err(self.span(node, value.into()))
    }

    fn parse(&mut self, root_node: &tree_sitter::Node) -> ParseResult<SourceFile> {
        match root_node.kind() {
            "source_file" => {
                let definitions = root_node
                    .children()
                    .filter_map(|node| match self.parse_call_definition(&node) {
                        Ok(call) => Some(call),
                        Err(err) => {
                            self.errors.push(err);
                            None
                        }
                    })
                    .collect();

                self.ok(
                    root_node,
                    SourceFile {
                        file: self.file_id,
                        definitions,
                    },
                )
            }
            kind => self.err(
                root_node,
                format!("[Internal] Unexpected node kind: {}", kind),
            ),
        }
    }

    fn parse_call_definition(&mut self, node: &tree_sitter::Node) -> ParseResult<Call> {
        let fn_name = node.child_by_field_name("fn").ok_or_else(|| {
            self.span(
                node,
                "[Internal] Expected call definition to have fn".to_string(),
            )
        })?;

        let name = self.parse_identifier(&fn_name)?;

        let params = self.parse_items(node);

        self.ok(node, Call { name, params })
    }

    fn parse_items(&mut self, node: &tree_sitter::Node) -> Vec<Rc<Span<Node>>> {
        let mut each_arg = node.child_by_field_name("items");
        let mut collected_items = vec![];
        while each_arg.is_some() {
            match each_arg {
                Some(arg) => {
                    collected_items.push(arg);
                    each_arg = arg.next_named_sibling()
                }
                _ => (),
            }
        }

        collected_items
            .iter()
            .filter_map(|node| match self.parse_statement(&node) {
                Ok(call) => Some(Rc::new(call)),
                Err(err) => {
                    self.errors.push(err);
                    None
                }
            })
            .collect()
    }

    fn parse_identifier(&mut self, node: &tree_sitter::Node) -> ParseResult<String> {
        if node.kind() != "identifier" {
            self.err(
                node,
                format!(
                    "[Internal] Expected kind to be identifier, got \"{}\"",
                    node.kind()
                ),
            )
        } else {
            self.ok(
                node,
                format!("{}", &self.source[node.start_byte()..node.end_byte()]),
            )
        }
    }

    fn parse_string(&mut self, node: &tree_sitter::Node) -> ParseResult<String> {
        if node.kind() != "string" {
            self.err(
                node,
                format!(
                    "[Internal] Expected kind to be string, got \"{}\"",
                    node.kind()
                ),
            )
        } else {
            self.ok(
                node,
                format!(
                    "{}",
                    &self.source[node.start_byte() + 1..node.end_byte() - 1]
                ),
            )
        }
    }

    fn parse_number(&mut self, node: &tree_sitter::Node) -> ParseResult<usize> {
        use std::str::FromStr;
        if node.kind() != "number" {
            self.err(
                node,
                format!(
                    "[Internal] Expected kind to be number, got \"{}\"",
                    node.kind()
                ),
            )
        } else {
            let num = &self.source[node.start_byte()..node.end_byte()];
            self.ok(
                node,
                usize::from_str(&num.replace('\'', ""))
                    .map_err(|_| self.span(node, "Failed to parse number".to_string()))?,
            )
        }
    }

    fn parse_statement(&mut self, node: &tree_sitter::Node) -> ParseResult<Node> {
        match node.kind() {
            "call_definition" => self
                .parse_call_definition(node)
                .map(|call_def| self.span(node, Node::Call(call_def))),
            "identifier" => self
                .parse_identifier(node)
                .map(|id_def| self.span(node, Node::Identifier(id_def))),
            "string" => self
                .parse_string(node)
                .map(|str_def| self.span(node, Node::String(str_def))),
            "number" => self
                .parse_number(node)
                .map(|num_def| self.span(node, Node::Number(num_def))),
            "list_definition" => {
                let items = self.parse_items(node);
                self.ok(node, Node::List(self.span(node, List { items })))
            }
            other_kind => self.err(
                node,
                format!("[Internal] \"{}\" not implemented yet", other_kind),
            ),
        }
    }
}
