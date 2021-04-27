#include<iostream>
#include<string>
#include<stack>
// cstdlib is needed for atoi()
#include <cstdlib>

using namespace std;

class EvalPostfix {
		private:
			string expression;
			int result;
		public:
			EvalPostfix(string st) {
				expression = st;
			}
	
			void eval_expression() {
				stack<string> s;
			
				string exp = expression, last_element;
				int operand_1, operand_2, res;

				for (int i = 0; i < exp.length(); i++) {
					switch(exp[i]) {
						case '*':
						case '/':
						case '-':
						case '+':
							if (exp[i+1] == ',' || (i+1) == expression.length()) {
								while (s.top() == ",")
									s.pop();

								operand_2 = stoi(s.top());
								s.pop();

								while (s.top() == ",")
									s.pop();

								operand_1 = stoi(s.top());
								s.pop();

								if (exp[i] == '*')
									res = operand_1 * operand_2;

								if (exp[i] == '/')
									res = operand_1 / operand_2;

								if (exp[i] == '+')
									res = operand_1 + operand_2;

								if (exp[i] == '-')
									res = operand_1 - operand_2;

								s.push(to_string(res));
							} else {
								s.push(string(1, exp[i]));
							}

						break;
						case '1':
						case '2':
						case '3':
						case '4':
						case '5':
						case '6':
						case '7':
						case '8':
						case '9':
						case '0':
							last_element = (!s.empty() ? s.top():"");

							if (last_element == ",") 
								last_element = "";
							else if (last_element != "," && !s.empty())
								s.pop();
								
							last_element += exp[i];
							s.push(last_element);
							
						break;
						case ',':
							s.push(",");
						break;
					}
				}

				result = stoi(s.top());
				s.pop();
			}

			void print_result() {
				cout << "The result of postfix expression is: " << result << endl;
			}

};

int main() {
	string exp;

	cout << "Enter an postfix expression > ";
	getline(cin, exp);	
		
	EvalPostfix EPF(exp);

	EPF.eval_expression();
	EPF.print_result();

	return 1;
}
