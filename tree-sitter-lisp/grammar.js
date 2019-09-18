module.exports = grammar({
    name: 'lisp',
    rules: {
        source_file: $ => repeat($.call_definition),
        _statement: $ => choice(
            $.call_definition,
            $.list_definition,
            $.string,
            $.identifier,
            $.number
        ),
        call_definition: $ => seq(
            '(',
            field('fn', $.identifier),
            field('items', repeat($._statement)),
            ')'
        ),
        list_definition: $ => seq(
            '[',
            field('items', repeat($._statement)),
            ']'
        ),
        identifier: $ => /[a-zA-Z_\-\+\/@!?><][0-9a-zA-Z_\-+\/@!?><]*/,
        number: $ => /\d+('?\d+)*/,
        _string_contents: $ => choice(
            $.string_escape,
            $.string_content
        ),
        string_escape: $ => /\\["\\a-z0-9]/,
        string_content: $ => /[^\\"]+/,
        string: $ => seq(
            '"',
            repeat($._string_contents),
            '"',
        ),
    }
})