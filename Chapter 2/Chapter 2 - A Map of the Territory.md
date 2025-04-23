### 2.1 - The Parts of a Language
##### 2.1.1 - Scanning
- scanning, or lexing
- takes in the linear stream of characters and chunks them together into a series of something more akin to "words"
- each of the words in a programming language is called a token
- some characters in a source file don't actually mean anything
	- whitespace is often insignificant
	- comments are ignored by the language
##### 2.1.2 - Parsing
- where our syntax gets a grammar
- parser takes the flat sequence of tokens and builds a tree structure that mirrors the nested nature of the grammar
	- parse tree or abstract syntax tree
- parsers job also includes reporting syntax errors
##### 2.1.3 - Static Analysis
- binding or resolution
	- for each identifier, we find out where that name is defined and wire the two together
	- scope - the region of source code where a certain name can be used to refer to a certain declaration
- type checking
	- only for statically typed languages
	- figure out types
- the semantic insight that is visible to us from analysis needs to be stored
	- stored back as attributes on the syntax tree itself - extra fields in the nodes that aren't initialized during parsing but get filled in later
	- store data in a lookup table off to the side
		- symbol table - the keys in the lookup tables and the values it associates with each key tell us what the identifier refers to
	- transform the tree into an entirely new data structure that more directly expresses the semantics of the code
##### 2.1.4 - Intermediate Representations
- the compiler is a pipeline where each stage's job is to organize the data representing the user's code in a way that makes the next stage simpler to implement
- code may be stored in some intermediate representation (IR) that isn't tightly tied to either the source or destination forms
- a way to target languages and backend's without creating unique compilers for each back-end
##### 2.1.5 - Optimization
- free to swap code out with a different program that has the same semantics but implements them more efficiently
##### 2.1.6 - Code Generation
- generating code
	- converting source code to a form that the machine can actually run
- representation of the code becomes more and more primitive
- do we generate instructions for a real CPU or a virtual one?
	- if we generate real machine code, we get an executable that the OS can directly load onto the chip
	- create instructions for hypothetical machine, bytecode
##### 2.1.7 - Virtual Machine
- a program that emulates a hypothetical chip supporting your virtual architecture at runtime
- every instruction must be simulated at runtime each time it executes
### 2.2 - Shortcuts and Alternate Routes