#include <iostream>
#define MAX_ARRAY_SIZE 5
using namespace std;
class CircularArray {
	private:
		int arr[MAX_ARRAY_SIZE];
		int current_index = 0;
	public:
		void init_array() {
			cout << "init_array()" << endl;
			for(int i = 0 ; i < 10; i++) {
				arr[ (i+1) % MAX_ARRAY_SIZE ] = i;
				current_index = (i+1) % MAX_ARRAY_SIZE; 
			}
		}

		void print_array_circular() {
			cout << "print_array_circular()" << endl;
			for ( int i = 0; i < 5; i++) {
				cout << arr[ (current_index + i + 1) % MAX_ARRAY_SIZE] << endl;
			}
		}

		void print_array_flat() {
			cout << "print_array_flat()" << endl;
			for ( int i = 0; i < 5; i++) {
				cout << arr[i] << endl;
			}
		}

};

int main () {
	CircularArray CA;
	CA.init_array();
	CA.print_array_flat();
	CA.print_array_circular();

	return 1;
}
