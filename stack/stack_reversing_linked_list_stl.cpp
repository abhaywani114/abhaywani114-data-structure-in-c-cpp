#include <iostream>
#include <stack>

using namespace std;

class linked_list {
	private:
		struct node {
			int data;
			node * next;
		};
		node * head = NULL, * last = NULL;
	public:
		void insert_node(int data) {
			cout << "insert_node(" << data << ")" << endl;

			node * new_node = new node();
			new_node->next = NULL;
			new_node->data = data;

			if (head == NULL) {
				head = new_node;	
			} else {
				last->next = new_node;	
			}

			last = new_node;
		}
	
		void print_linked_list() {
			cout << endl << "Printing Linked List" << endl;
			node * temp_head = head;
			while(temp_head != NULL) {
				cout << "\t" << temp_head->data;
				temp_head = temp_head->next;
			}
			cout << endl;
		}

		void reverse_linked_list_using_stack() {
			cout << endl << "reverse_linked_list_using_stack()" << endl;
			stack<node *> node_stack;	
			node * temp_head = head;
			
			while (temp_head != NULL) {
				node_stack.push(temp_head);
				temp_head = temp_head->next;
			}
			
			head = node_stack.top();
			last = head;
			node_stack.pop();
			
			while(!node_stack.empty()) {
				last->next = node_stack.top();
				last 	 = last->next;
				node_stack.pop();
			}
		
			last->next = NULL;
		}
};

int main() {
	linked_list l1;
	l1.insert_node(1);
	l1.insert_node(2);
	l1.insert_node(3);
	l1.insert_node(4);
	l1.print_linked_list();
	l1.reverse_linked_list_using_stack();
	l1.print_linked_list();
	return 1;
}
