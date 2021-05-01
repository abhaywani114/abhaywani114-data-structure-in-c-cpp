#include<iostream>
#include<string>
#include<stack>

using namespace std;

class InfixToPostfix {
	private:
		string infix_expression;
		string postfix_expression;

	public:
		InfixToPostfix(string expression) {
			infix_expression = expression;
			postfix_expression = "";
			convert_exp_postfix();
		}

		void print_postfix() {
			cout << "Postfix expression is: " << postfix_expression << endl;
		}
		
		void convert_exp_postfix() {
			stack<char> _operator;
			for(int i = 0; i < infix_expression.length(); i++) {
				
				if (infix_expression[i] == '+' || infix_expression[i] == '-' || 
					infix_expression[i] == '/' || infix_expression[i] == '*') {

					if (_operator.empty()) {
						_operator.push(infix_expression[i]);
					} else {
					
						if (infix_expression[i] == '*') {
							if (_operator.top() == '-' || _operator.top() == '+' || _operator.top() == '/') {
								_operator.push(infix_expression[i]);
							} else {
								empty_stack(&_operator);
								_operator.push(infix_expression[i]);
							}
						}
						
						if (infix_expression[i] == '/') {
							if (_operator.top() == '-' || _operator.top() == '+' || _operator.top() == '/' ) {
								_operator.push(infix_expression[i]);
							} else {
								empty_stack(&_operator);
								_operator.push(infix_expression[i]);
							}

						}

						if (infix_expression[i] == '+') {
							if (_operator.top() == '*' || _operator.top() == '/' || _operator.top() == '+') {
								empty_stack(&_operator);
								_operator.push(infix_expression[i]);
							}
						}

						if (infix_expression[i] == '-') {
							if (_operator.top() == '*' || _operator.top() == '/' || _operator.top() == '+' || _operator.top() == '-') {
								empty_stack(&_operator);
								_operator.push(infix_expression[i]);
							}
						}
					}	

				} else if (infix_expression[i] == '1' || infix_expression[i] == '2' || infix_expression[i] == '3' || 
						infix_expression[i] == '4' || infix_expression[i] == '5' || infix_expression[i] == '6' || 
						infix_expression[i] == '7' || infix_expression[i] == '8' || infix_expression[i] == '9' || 
						infix_expression[i] == '0') {
						postfix_expression += infix_expression[i];
				}
			}
			
			empty_stack(&_operator);
		}

		void empty_stack (stack<char> * _operator) {
			while(!(*_operator).empty()) {
				postfix_expression += (*_operator).top();
				(*_operator).pop();
			}
		}
};

int main() {
	string exp;
	cout << "Enter infix expression> ";
	getline(cin, exp);
	
	InfixToPostfix ITP(exp);
	
	ITP.print_postfix();
	
	return 1;
}
