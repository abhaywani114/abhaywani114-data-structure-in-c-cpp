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
				stack<int> s;
			
				string exp = expression;
				int operand_1, operand_2, last_element;

				for (int i = 0; i < exp.length(); i++) {
					switch(exp[i]) {
						case '*':
						case '/':
						case '-':
						case '+':
							while (s.top() == -1)
								s.pop();

							operand_2 = s.top();
							s.pop();

							while (s.top() == -1)
								s.pop();

							operand_1 = s.top();
							s.pop();

							if (exp[i] == '*')
								last_element = operand_1 * operand_2;

							if (exp[i] == '/')
								last_element = operand_1 / operand_2;

							if (exp[i] == '+')
								last_element = operand_1 + operand_2;

							if (exp[i] == '-')
								last_element = operand_1 - operand_2;

							s.push(last_element);
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
							last_element = (!s.empty() ? s.top():-1);
						
							if (last_element == -1) {
								last_element = 0;
								s.push(last_element);
							}

							if (last_element != -1) {
								string temp_st = to_string(last_element);
								temp_st += exp[i];
								last_element = stoi(temp_st);
								s.pop();
								s.push(last_element);
							} 
					
						break;
						case ',':
							s.push(-1);
						break;
					}
				}

				result = s.top();
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
