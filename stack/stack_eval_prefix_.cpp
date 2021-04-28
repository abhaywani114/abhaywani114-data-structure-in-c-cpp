#include<iostream>
#include<string>
#include<stack>

using namespace std;

class PrefixEval {
	private:
		string expression;
		stack<string> prefix_stack;
		int result_exp;
		bool is_valid = true;

	public:
		PrefixEval(string st) {
			expression = st;
		}

		void print_result() {
			if (is_valid == true)
				cout << "The evaluation of prefix expression is: " << result_exp << endl;
			else
				cout << "Invalid prefix expression" << endl;
		}

		int getOperand() {
			int operand = 0;
			if (prefix_stack.empty()) {
				is_valid = false;
			} else {
				while (prefix_stack.top() == ",")
					prefix_stack.pop();
				operand = stoi(prefix_stack.top());
				prefix_stack.pop();
			}
			
			return operand;
		}

		void eval_prefix_expression() {
			string last_element;
			int operand_1, operand_2,result;

			for (int i = expression.length() - 1; i >= 0; i--) {
				switch(expression[i]) {
					case '+':
					case '-':
					case '*':
					case '/':
						if (expression[i+1] == ',') {
							operand_1 = getOperand();
							operand_2 = getOperand();
							
							if (expression[i] == '*')
								result = operand_1 * operand_2;					

							if (expression[i] == '/')
								result = operand_1 / operand_2;					

							if (expression[i] == '+')
								result = operand_1 + operand_2;					

							if (expression[i] == '-')
								result = operand_1 - operand_2;					

							//cout << operand_1 << " " << expression[i] << " " << operand_2 << " = " <<  result << endl;

							prefix_stack.push(to_string(result));
						} else {

							if(expression[i+1] == '-')
								goto process_number;
							else
								is_valid = false;
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
						process_number:
						last_element = prefix_stack.empty() ? "": (prefix_stack.top() == "," ? "":prefix_stack.top());
						
						if (!prefix_stack.empty())	
							if (prefix_stack.top() != ",")
								prefix_stack.pop();

						last_element = expression[i] + last_element;
						prefix_stack.push(last_element);

						break;
					case ',':
						prefix_stack.push(",");	
						break;
					default:
						is_valid = false;
						break;
				}

				if (is_valid == false)
					return;
			}
			
			result_exp = stoi(prefix_stack.top());
		}
};

int main() {
	string exp;
	
	cout << "Enter a prefix expression (delimeter ,) > ";
	getline(cin ,exp);

	PrefixEval PFE(exp);
	PFE.eval_prefix_expression();
	PFE.print_result();
	return 1;
}
