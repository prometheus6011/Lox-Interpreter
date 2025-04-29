### 3.1 - Hello, Lox
```
// your first Lox program!
print "Hello, wordl!";
```
- Lox's syntax is a member of the C family
### 3.2 - A High-Level Language
- Lox itself is pretty compact
##### 3.2.1 - Dynamic Typing
- variables can store values of any type, and a single variable can even store values of different types at different times
##### 3.2.2 - Automatic Memory Management
- reference counting
	- simpler to implement but limitations make it more troublesome
- tracing garbage collection
### 3.3 - Data Types
- booleans
	- true and false values
```
true;
false;
```
- numbers
	- double-precision floating point
```
1234;
12.34;
```
- strings
	- string literals enclosed in double quotes
```
"I am a string";
"";
"123";
```
- Nil
	- no value
### 3.4 - Expressions
##### 3.4.1 - Arithmetic
- features the basic arithmetic operators
```
add + me;
subtract - me;
multiply * me;
divide / me;
```
- subexpressions on either side of the operator are operands
- the `-` operator can also be used to negate a number
##### 3.4.1 - Comparison and Equality
- compare numbers
```
lass < than;
lessThan <= orEqual;
greater > than;
greaterThan >= orEqual;
```
- equality or inequality
```
1 == 2;
"cat" != "dog";
```
- values of different types are never equivalent
##### 3.4.3 - Logical operators
- the not operator, `!`, returns `false` if the operand is true
```
!true;
!false;
```
- other two logical operators really are control flow constructs in the guise of expressions
```
true and false;
true and true;

false or false;
true or false;
```
- short circuit
##### 3.4.4 - Precedence and Grouping
- have the same precedence and associativity that you'd expect coming from C
- use `()` to force grouping
```
var average = (min + max) / 2;
```
### 3.5 - Statements
- expression's main job is to produce a value, a statement's job is to produce an effect
- a `print` statement evaluates a single expression and displays the result to the user
- an expression followed by a semicolon, `;` promotes the expression to statement-hood, expression statement
- packing a series of statement where a single one is expected, you can wrap them in a block
```
{
	print "One statement.";
	print "Two statements.";
}
```
### 3.6 - Variables
- declare variables using `var` statements, the variable's value defaults to `nil`
```
var imAVariable = "here is my value";
var iAmNil;
```
- access a variable using its name
```
var breakfast = "bagels";
print breakfast;
breakfast = "beignets";
print breakfast;
```
### 3.7 - Control Flow
- `if` statement executes one of two statements based on some condition
```
if (condition) {
	print "yes";
} else {
	print "no";
}
```
- a `while` loop executes the body repeatedly as long as the condition expression evaluates to `true`
```
var a = 1;
while (a < 10) {
	print a;
	a = a + 1;
}
```
- `for` loops
```
for (var a = 1; a < 10; a = a + 1) {
	print a;
}
```
### 3.8 - Functions
- function calls looks the same as it does in C
- function definitions start with `fun`
```
fun printSum(a, b) {
	print a + b;
}
```
- an argument is an actual value that you pass to a function when you call it, a function call has an argument list
- a parameter is a variable that holds the value of the argument inside the body of the function, a function declaration has a parameter list
- the body of a function is always a block, return a value using a `return` statement
- if there is no `return` at the end of the block, the function implicitly returns `nil`
##### 3.8.1 - Closures
- first class functions, they are real values that you can get a reference to, store in variables, pass around
```
fun addPair(a, b) {
	return a + b;
}

fun identity(a) {
	return a;
}

print identity(addPair)(1, 2);
```
- declare local functions inside another function
```
fun outerFunction() {
	fun localFunction() {
		print "I'm local!";
	}

	localFunction();
}
```
- closures as function close over variables within functions
### 3.9 - Classes
##### 3.9.1 - Why might any language want to be object oriented?
- we need some way of defining compound types to bundle blobs of stuff together
##### 3.9.2 - Why is Lox object oriented?
##### 3.9.3 - Classes or Prototypes
- in class based languages
	- instances
		- store the state for each object and have a reference to the instance's class
	- classes
		- contain the methods and inheritance chain
- prototype-based languages
	- only objects and each individual object may contain state and methods
##### 3.9.4 - Classes in Lox
- class declaration
```
class Breakfast {
	cook() {
		print "Eggs a-fryin`!";
	}

	serve(who) {
		print "Enjoy your breakfast, " + who + ".";
	}
}
```