#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	stack<char> stack_ch;
	string user_input;
	char current_char;

	cout << "Enter an expression to check> " << endl << "> ";
	getline(cin, user_input);

	for(int i = 0; i < user_input.length(); i++) {
			current_char = user_input[i];
			
			if (current_char == '(' || current_char == '{' || current_char == '[')
				stack_ch.push(current_char);
			else if ((current_char == ')' || current_char == '}' || current_char == ']') && stack_ch.empty()) {
					stack_ch.push('E'); // making stack non-empty brefore breaking off
					break;
			}
	
			if (current_char == ')' && stack_ch.top() == '(')
				stack_ch.pop();

			if (current_char == ']' && stack_ch.top() == '[')
				stack_ch.pop();

			if (current_char == '}' && stack_ch.top() == '{')
				stack_ch.pop();
		}

		if (!stack_ch.empty())
			cout << "String is not balanced" << endl;
		else
			cout << "String is balanced" << endl;

		return 1; 
}
