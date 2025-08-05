## C Compiler

This compiler compiles a subset of the C programming language into machine code.

It has a few distinct stages
- a scanner
- parser
- semantic analysis
- code generation

and can compile a variety of C programs.

## Ideal Project Structure

wlp4-compiler/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/
│   ├── scanner/
│   │   └── scanner.h
│   ├── parser/
│   │   └── parser.h
│   ├── semantic/
│   │   └── semantic_analyzer.h
│   ├── codegen/
│   │   └── code_generator.h
│   └── common/
│       ├── token.h
│       ├── ast.h
│       └── symbol_table.h
├── src/
│   ├── scanner/
│   │   └── scanner.cpp
│   ├── parser/
│   │   └── parser.cpp
│   ├── semantic/
│   │   └── semantic_analyzer.cpp
│   ├── codegen/
│   │   └── code_generator.cpp
│   ├── common/
│   │   ├── token.cpp
│   │   ├── ast.cpp
│   │   └── symbol_table.cpp
│   └── main.cpp
├── tests/
│   ├── unit/
│   ├── integration/
│   └── examples/
└── docs/
    └── architecture.md