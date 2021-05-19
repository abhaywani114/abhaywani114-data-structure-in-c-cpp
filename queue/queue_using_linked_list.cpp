#include <iostream>
using namespace std;

class QueueLinkedList {
	private:
		struct node {
			int data;
			node * next;
		};
		node * front = NULL;
		node * rear = NULL;
	public:	
		void enqueue(int val) {
			cout << "enqueue(" << val << ")" << endl;
			node *temp_node = new node();
			temp_node->data = val;
			temp_node->next = NULL;

			if (rear != NULL) {
				rear->next = temp_node;
			}
			
			if (front == NULL)
				front = temp_node;
			
			rear = temp_node;
		}
	
		void dequeue() {
			cout << "dequeue()" << endl;

			if (front != NULL) {
				node *temp_node = front;
				front = temp_node->next;
				cout << "dequeueing: " << temp_node->data << endl;
				delete temp_node;
			} else {
				cout << "queue is empty" << endl;
			}
		}
		
		
};

int main() {
	QueueLinkedList q;
	
	q.dequeue();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	q.dequeue();
	return 1;
}
