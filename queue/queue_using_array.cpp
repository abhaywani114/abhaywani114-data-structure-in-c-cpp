#include<iostream>
using namespace std;

class QueueUsingArr {
	private:
		int front_index = -1;
		int rear_index = -1;
		int arr[100];
	public:
		void enqueue(int x) {
			cout << "enqueue(" << x << ")" << endl;
			if (front_index == -1 && rear_index == -1) {
				arr[1] = x;
				front_index = rear_index = 1;
			}	else {
				rear_index++;
				arr[rear_index] = x;
			}
		}
		
		bool isEmpty() {
			cout << (rear_index == -1 ? "Queue is empty": "Queue is not empty") << endl;
			return rear_index == -1;
		}

		int front() {
			return arr[front_index];
		}

		void dequeue() {
			cout << "dequeue()" << endl;
			front_index++;
			if (front_index > rear_index) {
				front_index = rear_index = -1;
			}
		}
};

int main() {
	QueueUsingArr QUA;
	QUA.isEmpty();
	QUA.enqueue(1);
	QUA.isEmpty();
	QUA.enqueue(2);
	cout << "front: " << QUA.front() << endl;
	QUA.dequeue();
	cout << "front: " << QUA.front() << endl;
	QUA.dequeue();
	QUA.isEmpty();
	QUA.enqueue(3);
	cout << "front: " << QUA.front() << endl;
	return 1;
}
