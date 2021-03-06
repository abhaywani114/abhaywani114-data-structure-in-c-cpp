#include <iostream>
using namespace std;

class linked_list {
	private:
		struct node {
			int data;
			node* next;
		};
		node* head = NULL;

		void print_recursive_forward(node * node) {
			if (node == NULL)
				return;

			printf("\t%d", node->data);
			print_recursive_forward(node->next);
		}
		
		void print_recursive_reverse(node * node) {
			if (node == NULL)
				return;

			print_recursive_reverse(node->next);
			printf("\t%d", node->data);
		}

		void reverse_linked_list_recursion(node * start) {
			if (start->next == NULL) {
				head = start;
				return;
			}

			reverse_linked_list_recursion(start->next);

			node *temp = start->next;
			temp->next = start;
			start->next = NULL;
		}

	
	public:
		void insert(int pos, int val) {
			cout << "insert(" << pos << "," << val << ")" << endl;
			//creating a new node
			node* temp = new node();
			temp->data = val;
			temp->next = NULL;
			
			//adjusting links


			//if at begnning
			if (pos == 0) {
				if (head != NULL)
					temp->next = head;
				head = temp;	
			}
	
			// if in between
			if (pos > 0) {
				node* temp2 = head;
				for (int i = 0; i < pos - 1; i++)
					if (temp2->next != NULL)
						temp2 = temp2->next;
				temp->next = temp2->next;
				temp2->next = temp;
			}

			//if at end
			if (pos == -1) {
				node* temp2 = head;
				while (temp2->next != NULL)
					temp2 = temp2->next;
				temp2->next = temp;
			}
		
			print();
		}

		void print() {
			node* temp = head;
			cout << "Printing linked List: ";
			while(temp != NULL) {
				cout << "\t" << temp->data;
				temp = temp->next;
			}	
			
			cout << endl << endl;
		}

		void print_recursive(bool is_reverse = false) {
			cout << endl << "print_recursive( is_reverse = " << is_reverse << ")" << endl;

			cout << "Printing linked List (recursive): ";
			if (is_reverse == false)
				print_recursive_forward(head);
			else
				print_recursive_reverse(head);

			cout << endl;
		}
			
		void delete_node(int pos) {
			cout << "delete(" << pos << ")" << endl;
			
			node* temp = head, *temp2 = NULL;
			
			if (pos > 1) {
				// i < pos - 2 because we want pos as natural numbers
				for (int i = 0; i < pos - 2; i++)
					temp = temp->next;
				
				temp2 = temp->next;
				
				if (temp->next != NULL)
					temp->next = temp->next->next;
				else
					temp->next = NULL;

				delete temp2;
			}

			if (pos == 1) {
				temp2 = head;
				head = head->next;
				delete temp2;
			} 
		}

		/*
			Algorithm:
				1. init prev = NULL
				2. Select a node, temp
				3. set temp2 = temp
				4. set temp = temp->next
				5. temp2->next = prev
				6. prev = temp2
				7. if temp != NULL GOTO 3
				8. set head = prev
		*/

		void reverse_linked_list() {
			cout << "reverse_linked_list()" << endl;
			node *temp = head, *temp2 = NULL,*prev = NULL;
			
			while (temp != NULL) {
				temp2 = temp;
				temp = temp->next;
				temp2->next = prev;
				prev = temp2;
			}

			head = prev;
		}

		void reverse_linked_list_recursion() {
			cout << endl << "reverse_linked_list_recursion()" << endl;
			reverse_linked_list_recursion(head);
		}
};

int main() {
	linked_list l1;
	l1.insert(0, 1);
	l1.insert(-1, 2);	
	l1.insert(-1, 4);	
	l1.insert(1, 6);
	l1.insert(0, -1);	

	//delete
	l1.delete_node(3);
	l1.print();

	//reverse
	l1.reverse_linked_list();
	l1.print();

	//recursive Print
	l1.print_recursive(true); 
	l1.print_recursive(); 

	//recursive Reverse
	l1.reverse_linked_list_recursion();
	l1.print();

	return 1;
}
