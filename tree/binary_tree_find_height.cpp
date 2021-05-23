#include<iostream>
using namespace std;

class BST {
	private:
		struct node {
			int data;
			node * left_child;
			node * right_child;
		};	
		
		
		node * appendTree(node * rootPtr, node * new_node) {
			if (rootPtr == NULL) {
				rootPtr = new_node;
			} else if (new_node->data <= rootPtr->data){
				rootPtr->left_child = appendTree(rootPtr->left_child ,new_node);
			} else {
				rootPtr->right_child =  appendTree(rootPtr->right_child ,new_node);
			}
			
			return rootPtr;
		}

		node * root = NULL;

	public:
		node * getRoot() {
			return root;
		}
		/**
		* inserts a new node into the BST (RECURSIVE)
		* @param data the value of node
		*/
		void insertNode(int data) {
			cout << "insertNode(" << data << ")" << endl;
			node * new_node = new node();
			new_node->left_child = NULL;
			new_node->right_child = NULL;
			new_node->data = data;

			if (root == NULL) {
				root = new_node;
			} else {
				appendTree(root, new_node);
			}
		}		

		/**
		* inserts a new node into the BST (NON-RECURSIVE)
		* @param data the value of node
		*/
		void insertNodeNR(int data) {
			cout << "insertNodeNR(" << data << ")" << endl;
			node * temp_node = root; 
					
			node * new_node = new node();
			new_node->left_child = NULL;
			new_node->right_child = NULL;
			new_node->data = data;
		
			while (1) {
				if(temp_node->data >= new_node->data) {
					if (temp_node->left_child != NULL)
						temp_node = temp_node->left_child;
					else {
						temp_node->left_child = new_node;
						break;
					}
				} else {
					if (temp_node->right_child != NULL)
						temp_node = temp_node->right_child;
					else {
						temp_node->right_child = new_node;
						break;
					}
				}
			}

		}

		/**
		*	Print the BST
		*/
		void printBST(node * rootPtr) {
			if (rootPtr == NULL) return;

			printBST(rootPtr->left_child);
			cout << rootPtr->data << "\t";
			printBST(rootPtr->right_child);
		}

		/**
		* Find the height of binary search tree
		* @param rootPtr BST's root ptr
		* @return max(no_left_node, no_right_node)
		*/
		int heightBST(node * rootPtr) {
			int x = 1, y = 1;	

			if (rootPtr == NULL) return -1;

			x += heightBST(rootPtr->right_child);
			y += heightBST(rootPtr->left_child);

			return max(x,y);
		}
		
};

int main() {
	BST b1;
	// Recursive mode
	b1.insertNode(50);	
	b1.insertNode(20);	
	b1.insertNode(15);	
	b1.insertNode(7);	
	b1.insertNode(2);	
	b1.insertNode(60);

	//Non Recursive mode	
	b1.insertNodeNR(10);	
	b1.insertNodeNR(1);	

	b1.printBST(b1.getRoot());
	cout << "\nheightBST():\n" << b1.heightBST(b1.getRoot()) << endl;
	return 1;
}
