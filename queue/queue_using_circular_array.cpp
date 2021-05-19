#include<iostream>
#define SIZE_ 3
using namespace std;

class QueueCirArr {
	private:
		int arr[SIZE_];
		int front = -1;
		int rear = -1;
	
	public:
		void enqueue(int val) {
			cout << "enqueue(" << val << ")" << endl;
			int rear_new = (rear + 1) % SIZE_;
			if (front == -1 && rear == -1) {
				arr[0] = val;
				front++;
				rear++;
			} else if (rear_new != front) {
				arr[rear_new] = val;
				rear = rear_new;
			} else {
				cout << "Queue is full" << endl;;
			}
		}

		void dequeue() {
			int new_front = (front + 1) % SIZE_;
				
			if (front == rear && front != -1) {
				cout << "dequeue(): " << arr[front] << endl;
				front = -1;
				rear = -1;
			} else if (front != -1) {
				cout << "dequeue(): " << arr[front] << endl;
				front = new_front;
			} else {
				cout << "dequeue(): queue is empty" <<endl;
			}

		}
};

int main() {
	QueueCirArr q;
	q.enqueue(1);	
	q.enqueue(2);	
	q.enqueue(3);	
	q.enqueue(4);	

	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.dequeue();

	return 1;
}
