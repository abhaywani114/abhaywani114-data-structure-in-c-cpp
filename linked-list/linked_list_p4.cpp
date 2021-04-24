#include <iostream>
using namespace std;

class doubly_linked_list {
	private:
		//basic node structure
		struct node {
			int data;
			node * prev;
			node * next;
		};
		
		//head pointer
		struct node *head = NULL;
	public:
		void insert_node(int data) {
			node * new_node = new node();
			new_node->data = data;

			if (head != NULL) {
				node * temp_node = head;

				while(temp_node->next != NULL)
					temp_node = temp_node->next;
				
				temp_node->next = new_node;
				new_node->prev = temp_node;
			}

			if (head == NULL) {
				new_node->prev = NULL;
				new_node->next = NULL;
				head = new_node;
			}	
		}

		void print_node() {
			node * temp_node = head;
			cout << "Printing Linked List> ";

			while(temp_node != NULL) {
				printf("\t%d", temp_node->data);
				temp_node = temp_node->next;
			}
			
			cout << endl;	
		}
		
};

int main() {
	int no_nodes, temp;
	doubly_linked_list dbl;
	cout << "How many nodes you want? ";
	cin >> no_nodes;
		
	for(int i = 0; i < no_nodes; i++) {
		cout << "Enter a value> ";
		cin >> temp;
		dbl.insert_node(temp);	
		dbl.print_node();
	}
		
	return 1;
}
