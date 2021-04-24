#include<iostream>
using namespace std;
#define SIZE 100

class Stack {
	private:
		int stack_array[SIZE], top = -1;
	public:
		void push(int x) {
			cout << "push(" << x << ")" << endl;
			
			if (top == SIZE - 1) {
				cout << "Stack is full" << endl;
				return;
			}	

			stack_array[++top] = x;
		}

		int pop() {
			if (!isEmpty()) {
				return stack_array[--top];
			} else {
				return -1;
			}
		}
		
		bool isEmpty() {
			return top == -1;
		}
		
		int top_element() {
			if (!isEmpty())
				return stack_array[top];
			else
				return -1;
		}
};

int main() {
	int option, temp;
	Stack s1;
	cout << "Stack implementation using arrays" << endl;
	cout << "1. Push an element " << endl;
	cout << "2. Pop an element" << endl;
	cout << "3. Is stack empty? " << endl;
	cout << "4. Top element " << endl;
	while (true) {
		cout << "Enter option> ";
		cin >> option;
		
		switch(option) {
			case 1:
				cout << "Enter value to push >";
				cin >> temp;
				s1.push(temp);
				break;
			case 2:
				cout << "Poping element " << s1.pop() << endl;
				break;
			case 3:
				cout << "Stack is: " << (s1.isEmpty() == true ? "Empty":"Not empty") << endl;
				break;
			case 4:
				if (!s1.isEmpty())
					cout << "Stack's top element is: " << s1.top_element() << endl;
				else
					cout << "No top element, stack is empty" << endl;
				break;
			default:
				cout << "Please enter a valid option!" << endl;
				break;
		}
	}
	return 1;
}
