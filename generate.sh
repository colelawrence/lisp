#!/bin/sh
cd ./tree-sitter-lisp
tree-sitter generate
cd ..
cargo build && cargo run
