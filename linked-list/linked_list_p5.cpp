#include <iostream>

using namespace std;

class circular_linked_list {
	private:
		struct node {
			int data;
			node *next;
			node *prev;
		};
		
		node * tail = NULL;
	public:
		void insert_node(int data) {
			node * new_node = new node();
			new_node->data = data;
			
			if (tail == NULL) {
				//pointing to self
				new_node->next = new_node;
				new_node->prev = new_node;
			}
		
			if (tail != NULL) {
				//poiting to head
				new_node->next = tail->next;
				
				//poiting to old tail
				new_node->prev = tail;
				
				//head poiting to last new node
				tail->next->prev  = new_node;
				
				//old tail pointing to new node
				tail->next = new_node;
			}
	
			// setting new tail
			tail = new_node;
		}

		void print_forward() {
			cout << endl << "print_forward()" << endl;
			node * temp = tail->next;
			do {
				printf("\t%d", temp->data);
				temp = temp->next;	
			} while (temp != tail->next);

			cout << endl;
		}
		
		void print_reverse() {
			cout << endl << "print_reverse()" << endl;
			node * temp = tail;
			do {
				printf("\t%d", temp->data);
				temp = temp->prev;	
			} while (temp != tail);

			cout << endl;
		}
	};

int main () {
	circular_linked_list cl1;
	int node_no, temp_inp;
	
	cout << "How many nodes you want to create for LL? ";
	cin >> node_no;

	for (int i = 0; i < node_no; i++) {
		cout << "Enter value for node > ";
		cin >> temp_inp;
		cl1.insert_node(temp_inp);
	}

	cl1.print_forward();
	cl1.print_reverse();
		
	return 1;
}
