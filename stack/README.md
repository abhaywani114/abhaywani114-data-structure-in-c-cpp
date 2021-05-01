#### What is stack? ####
A stack is a list with the restriction that insertion and deletion can be performed only from one end, i.e top. A stack always follow last-in-first-out (LIFO).

#### What are standard stack options? ####
The standard stack operation in stack are **push**, **pop**, **top**, and, **isEmpty**

#### What are some appilcations of stacks? ####
Some appilations of stacks are: **function calls**, **recursion**, **undo implementation**, and, **balanced parathesis*.


#### What is  Infix, Postfix and Prefix? ####
The way to write arithmetic expression is known as a notation. An arithmetic expression can be written in three different but equivalent notations, i.e., without changing the essence or output of an expression. These notations are:
- Infix Notation
- Prefix (Polish) Notation
- Postfix (Reverse-Polish) Notation

##### Infix Notation #####
We write expression in infix notation, e.g. a - b + c, where operators are used in-between operands. It is easy for us humans to read, write, and speak in infix notation but the same does not go well with computing devices. An algorithm to process infix notation could be difficult and costly in terms of time and space consumption.

##### Prefix Notation #####
In this notation, operator is prefixed to operands, i.e. operator is written ahead of operands. For example, +ab. This is equivalent to its infix notation a + b. Prefix notation is also known as Polish Notation.

##### Postfix Notation #####
This notation style is known as Reversed Polish Notation. In this notation style, the operator is postfixed to the operands i.e., the operator is written after the operands. For example, ab+. This is equivalent to its infix notation a + b.

> Reff: tutorialspoint.com

## Programs ###
- **stack_using_array_implementation:** demonstrating an *int stack* implementation using arrays in C++. 
- **stack_using_linked_list_implementation:** demonstrating an *int stack* implementation using linked list in C++. 
- **stack_reversing_string:** demonstrating an *string reversing* implementation using stack (linked list) in C. 
- **stack_reversing_linked_list_stl:** demonstrating an *linked list reversing* implementation using stack (STL) in C++. 
- **stack_check_balancing_parentheses** demonstrating balancing parentheses application of stacks using stack (STL) in C++.
- **stack_eval_postfix** evaluation of a postfix expression with expression validator using stack (STL) in c++ [Supports negetive numbers].
- **stack_eval_postfix_c** evaluation of a postfix expression with realtime self validator using stack (Linked List) in C [Supports negetive numbers].
- **stack_eval_prefix** evaluation of a prefix expression with realtime self validator using stack (STL) in C++ [Supports negetive numbers].
- **stack_infix_to_postfix** conversion of an infix expression into postfix expression using stack (STL) in C++.

> Note: Using arrays for stack implementation, worst case's time complexity is O(N).
