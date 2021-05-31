#include<iostream>
using namespace std;
#define SIZE 100

class havelHakimi {
	private:
		int degree_sequence[SIZE];
		int degree_sequence_count = 0;
	public:

		void setDegreeSequence(int arr[], int n) {
			degree_sequence_count = n;	
			for (int i = 0; i < degree_sequence_count; i++)
				degree_sequence[i] = arr[i];
		}
			
		void sortDegree() {
			//cout << "sortDegree()" << endl;
			int temp;
			for (int i = 0; i < degree_sequence_count; i++) {
				for (int j = (i+1); j < degree_sequence_count; j++) {
					if (degree_sequence[i] < degree_sequence[j]) {
						temp = degree_sequence[i];
						degree_sequence[i] = degree_sequence[j];
						degree_sequence[j] = temp;
					}
				}
			}

			degree_sequence_count -= countNumber(0);
		}
		
		int countNumber(int number) {
			int count_num = 0;

			for (int i = 0; i < degree_sequence_count; i++) {
				if (degree_sequence[i] == number)
					count_num++;
			}
		
			return count_num;
		}

		void printDegree() {
			cout << "degree_sequence: ";

			for(int i = 0; i < degree_sequence_count; i++)
				cout << degree_sequence[i] << "\t";

			cout << endl;
		}

		bool check() {
			sortDegree();

			if (degree_sequence_count < 1)
				return true;

			if (degree_sequence[0] > (degree_sequence_count-1))
				return false;

			int new_array[SIZE];

			for (int i = 1; i < degree_sequence_count; i++) {
				if (i <= degree_sequence[0])
					new_array[i - 1] = degree_sequence[i] - 1;
				else
					new_array[i - 1] = degree_sequence[i];

				if (new_array[i - 1] < 0)
					return false;
			}

			degree_sequence_count--;
			setDegreeSequence(new_array, degree_sequence_count);
			printDegree();
		
			return true;
		}

		void isValid() {
			cout << endl << "isValid(): checking if degree sequence is valid: " << endl;
			bool is_valid = true;

			printDegree();

			while(degree_sequence_count > 0) {
				is_valid = check();

				if (is_valid == false) {
					cout << "The graph is invalid" << endl;
					return;
				}
			}
			cout << "The graph is valid" << endl;
		}
		

};

int main() {
	int input_array[SIZE], input_count;
	havelHakimi HH;	
	cout << "Program: Havel-Hakimi theory implementation" << endl;
	cout << "Programed by: Abrar Ajaz <abhaywani114@gmail.com>\n" << endl;

	cout << "Enter no of vertex: ";
	cin >> input_count;

	for (int i = 0; i < input_count; i++) {
		cout << "Enter degree vertex at " << i << ": ";
		cin >> input_array[i];
	}
	
	HH.setDegreeSequence(input_array, input_count);
	HH.isValid();
}
