#include<iostream>
using namespace std;

class BST {
	private:
		struct BSTNode {
			int data;
			BSTNode * left_child;
			BSTNode * right_child;
		};
		BSTNode *root = NULL;
	public:

		void appendTree(int data) {
			root = appendTree(data, root);
		}
		
		BSTNode * appendTree(int data, BSTNode *root_ptr) {
			if (root_ptr == NULL) {
				BSTNode *new_node = new BSTNode();
				new_node->data = data;
				new_node->left_child = new_node->right_child = NULL;
				root_ptr = new_node;
				printf("Appending: %d\n", data);
			}
			else if (data <= root_ptr->data)
				 root_ptr->left_child = appendTree(data, root_ptr->left_child);
			else
				 root_ptr->right_child = appendTree(data, root_ptr->right_child);

			return root_ptr;
		}
		
		BSTNode * getRoot() {
			return root;
		}

		void printBST(BSTNode * root_ptr) {
			if (root_ptr == NULL) return;

			printBST(root_ptr->left_child);
			printf("%d\t", root_ptr->data);
			printBST(root_ptr->right_child);
		}

		BSTNode * searchNode(int data, BSTNode * rootPtr) {
			if (rootPtr == NULL) return NULL;

			if (data < rootPtr->data)
				searchNode(data, rootPtr->left_child);
			else if (data > rootPtr->data)
				searchNode(data, rootPtr->right_child);
			else
				return rootPtr;
		
		}
	
		int maxBST(BSTNode * rootPtr) {
			if (rootPtr->right_child != NULL)
				return maxBST(rootPtr->right_child);

			return rootPtr->data;
		}

		int getPredesisor(int data) {
			BSTNode *current_node = searchNode(data, root);
			if (current_node == NULL) return data;
			
			int int_pre = data;
			if (current_node->left_child != NULL)
				int_pre = maxBST(current_node->left_child);
			else {

				BSTNode *predisisor = root, * suscessor= root;
				while(suscessor != current_node) {

					if (data < suscessor->data) {
						suscessor = suscessor->left_child;
					} else {
						predisisor = suscessor;
						suscessor = suscessor->right_child;
					}
				}

				int_pre = predisisor->data;

				if (int_pre > data)
					int_pre = data;

			}

			printf("Predicessor: %d\n", int_pre);
			return int_pre;
		}
};

int main() {
	BST tree_1;
	tree_1.appendTree(15);
	tree_1.appendTree(9);
	tree_1.appendTree(2);
	tree_1.appendTree(10);
	tree_1.appendTree(12);
	tree_1.appendTree(11);
	tree_1.appendTree(20);
	tree_1.appendTree(25);
	tree_1.appendTree(17);

	tree_1.printBST(tree_1.getRoot());
	int x;
	while (true) {
		cout << "Enter a number to find previous number: " ;
		cin >> x;
		tree_1.getPredesisor(x);
	}
	return 1;
}
