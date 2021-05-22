#include<iostream>
using namespace std;

class BST {
	private:
		struct node {
			int data;
			node *left_child;
			node *right_child;
		};
	
		node * root = NULL; 

		node * insert_rec(node * rootPtr, node * new_node) {
			if (rootPtr == NULL) {
				rootPtr = new_node;
			} else if( new_node->data <= rootPtr->data) {
				rootPtr->left_child = insert_rec(rootPtr->left_child, new_node);
			} else if (new_node->data >= rootPtr->data) {
				rootPtr->right_child = insert_rec(rootPtr->right_child, new_node);
			}

			return rootPtr;
		}

		void printBST_rec(node * rootPtr) {

				if (rootPtr == NULL) return;

				printBST_rec(rootPtr->left_child);
				cout << rootPtr->data << "\t";
				printBST_rec(rootPtr->right_child);
		}
		 
		bool search_rec(node * rootPtr, int num) {
			if (rootPtr == NULL) 
				return false;
			else if (rootPtr->data == num)
				return true;
			else if (num > rootPtr->data)
				return search_rec(rootPtr->right_child, num);
			else if (num < rootPtr->data)
				return search_rec(rootPtr->left_child, num);
		}


	public:
		void insert(int val) {
			cout << "insert(" << val << ")" << endl;

			node *temp_node = new node();
			temp_node->data = val;
			temp_node->left_child = NULL;
			temp_node->right_child = NULL;

			root = insert_rec(root, temp_node);
		}

		void printBST() {
			cout << "printBST()" << endl;
			printBST_rec(root);
			cout << endl;
		}
		

		void search() {
			int number;
			cout << "search()" << endl;	
			cout << "Enter a number to search> ";
			cin >> number;

			if (search_rec(root, number))
				cout << "Number found in tree" << endl;
			else
				cout << "Number not found in tree" << endl;
		}
};

int main() {
	BST t1;

	t1.insert(50);	

	t1.insert(20);	

	t1.insert(60);	
	t1.insert(55);	

	t1.insert(30);	
	t1.insert(15);	
	t1.insert(14);	

	t1.printBST();	

	//t1.search();

	return 1;
}
