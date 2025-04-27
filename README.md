ONP Calculator

This project is a C++ implementation of an integer calculator that evaluates expressions in postfix notation (Reverse Polish Notation, RPN).
It converts valid infix expressions, which may include functions and operators, into postfix format while handling operator precedence and parentheses. 
The calculator supports various operations, including addition, subtraction, multiplication, division, unary negation, conditional evaluation with the IF function, and the MIN and MAX functions, which can take multiple arguments.
The program processes multiple formulas, printing each formula in postfix notation and displaying the contents of the stack before executing each operation.
The implementation uses a stack based on a list to manage operands and operators, ensuring efficient evaluation of expressions while adhering to memory management requirements to prevent leaks. 
The final result of each expression is displayed after evaluation.
