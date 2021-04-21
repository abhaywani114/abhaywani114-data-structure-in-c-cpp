#include <iostream>
using namespace std;

class linked_list {
	private:
		struct node {
			int data;
			node* next;
		};
		node* head = NULL;
	
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
	l1.delete_node(1);
	l1.print();

	return 1;
}
