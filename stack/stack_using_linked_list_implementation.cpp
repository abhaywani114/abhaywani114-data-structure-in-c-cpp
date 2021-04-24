#include<iostream>
using namespace std;

class stack_linked_list {
	private:
		struct node {
			int data;
			struct node *next;
		};
	
		struct node *top = NULL;

	public:
		void push(int x) {
			struct node *new_node = new node();
			new_node->data = x;
		
			if (top == NULL) {
				new_node->next = NULL;
				top = new_node;
				return;
			}

			new_node->next = top;
			top = new_node;
		}
		
		bool is_empty() {
			return top == NULL;
		}

		int top_element() {
			if (!is_empty())
				return top->data;
			else
				return -1;
		}

		int pop() {
			int return_val = top->data;
			node *temp = top;
			
			top = top->next;
			delete temp;

			return return_val;
		}

		void print() {
			node *temp_node = top;
			cout << "Printing all the stack!" << endl;
			
			while (temp_node != NULL) {
				cout << "\t" << temp_node->data;
				temp_node = temp_node->next;
			}
			
			cout << endl;
		}
};

int main() {
	stack_linked_list SLL;
	int option, temp_val;

     cout << "Stack implementation using arrays" << endl;
     cout << "1. Push an element " << endl;
     cout << "2. Pop an element" << endl;
     cout << "3. Is stack empty? " << endl;
     cout << "4. Top element " << endl;
	 cout << "5. Print stack" << endl << endl;	
	
	while(true) {
		cout << "Enter option> ";
		cin >> option;
		switch (option) {
			case 1:
				cout << "Enter value for node> ";
				cin >> temp_val;
				SLL.push(temp_val);
			break;

			case 2:

				if (!SLL.is_empty())
					cout << "Poping element " << SLL.pop() << endl;
				else
					cout << "Stack empty" << endl;
			break;

			case 3:
				cout << "Stack is: " << (SLL.is_empty() == true ? "Empty":"Not empty") << endl;
			break;

			case 4:
				if (!SLL.is_empty())
					cout << "Stack's top element is: " << SLL.top_element() << endl;
				else
					cout << "Stack is empty!" << endl;
			break;

			case 5:
				SLL.print();
			break;

			default:
				cout << "Please enter a valid option!" << endl;
			break;
		}
	}

	return 1;
}
