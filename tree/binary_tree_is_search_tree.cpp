#include<iostream>
#include<climits>
using namespace std;

class BST {
	public:
		struct BSTNode {
			int data;
			BSTNode * left_child;
			BSTNode * right_child;
		};

		BSTNode * root = NULL;

		/*
		* append Node in the BST
		* @param rootPtr root pointer of BST
		* @param new_node new node's pointer
		* @return rootPtr
		*/
		BSTNode * appendNode(BSTNode * rootPtr, BSTNode * new_node) {
			if (rootPtr == NULL)
				rootPtr = new_node;
			else if	(new_node->data <= rootPtr->data)
				rootPtr->left_child = appendNode(rootPtr->left_child, new_node);
			else	
				rootPtr->right_child = appendNode(rootPtr->right_child, new_node);

			return rootPtr;
		}

	public:
		/**
		*  get root pointer
		*  @return rootPtr 
		*/
		BSTNode * getRoot() {
			return root;
		}


		/**
		* insert data entry into BST
		* @param data the value of the node.
		*/
		void insertNode(int data) {
			cout << "insertNode(" << data << ")" << endl;
			BSTNode * new_node = new BSTNode();
			new_node->data = data;
			new_node->left_child = NULL;
			new_node->right_child = NULL;

			root = appendNode(root, new_node);
		}

		/**
		* print inorder sequence BST
		* @param rootPtr pointer of root node
		*/
		void printInorder(BSTNode * rootPtr) {
			if (rootPtr == NULL) return;
			
			printInorder(rootPtr->left_child);
			cout << rootPtr->data << "\t";
			printInorder(rootPtr->right_child);
		}

		/**
		* check if the tree is a binary search tree using range algorithm
		* @param rootPtr root pointer of BT
		* @param minVal minimun value range
		* @param maxVal maximum value range
		* @return bool if binary search tree
		*/
		bool isBST(BSTNode * rootPtr, int minVal, int maxVal) {
			if (rootPtr == NULL) return true;
		
			if (rootPtr->data < maxVal && rootPtr->data > minVal 
				&& isBST(rootPtr->left_child, minVal,rootPtr->data)
				&& isBST(rootPtr->right_child, rootPtr->data, maxVal))
				return true;
			else {
				return false;
			}

		}

		/**
		* check if the tree is a binary search tree using inorder algorithm
		* @param rootPtr root pointer of BT
		* @param pre_val previous node's value
		* @param is_left if rootPtr is previous node's left child
		* @return bool if binary search tree
		*/
		bool isBST_pre_order(BSTNode * rootPtr, int pre_val, bool is_left) {
			if (rootPtr == NULL) return true;
		
			bool isTree = true;	
			isTree = isTree && isBST_pre_order(rootPtr->left_child, rootPtr->data, true);
		
			// pre_val is the node visited
			// rootPtr is the preceding node	

			if (pre_val < rootPtr->data && is_left == true) {
				isTree = false;
			} else if (pre_val > rootPtr->data && is_left == false) {
				isTree = false;
			}

			isTree = isTree && isBST_pre_order(rootPtr->right_child, rootPtr->data, false);

			return isTree;
		}

		/**
		* find min in the BST
		* @param rootPtr root pointer of BST
		* @return min value in BST
		*/
		int minBST(BSTNode * rootPtr) {
				if (rootPtr->left_child != NULL)
				return minBST(rootPtr->left_child);
			
			return rootPtr->data;
		}

		/**
		* find max in the BST
		* @param rootPtr root pointer of BST
		* @return max value in BST
		*/

		int maxBST(BSTNode * rootPtr) {
			if (rootPtr->right_child != NULL)
				return minBST(rootPtr->left_child);
			
			return rootPtr->data;
		}

		/**
		* delete a node in BST
		* @param rootPtr root pointer of BST
		* @param prevNode previous node of BST
		* @param nodeVal value of the node to be deleted
		*/
		void deleteBSTNode(BSTNode * rootPtr, BSTNode * prevNode, int nodeVal) {
			if (rootPtr == NULL) return;
		
			if (rootPtr->data == nodeVal) {

				//Case: leaf node
				if (rootPtr->left_child == NULL && rootPtr->right_child == NULL) {
					if (prevNode->left_child == rootPtr)
						prevNode->left_child = NULL; 
					else
						prevNode->right_child =  NULL;

				} else if (rootPtr->left_child != NULL && rootPtr->right_child == NULL) {

					//Case if it has only: left child
					if (prevNode->left_child == rootPtr)
						prevNode->left_child = rootPtr->left_child;
					else
						prevNode->right_child = rootPtr->left_child;

				} else if (rootPtr->left_child == NULL && rootPtr->right_child != NULL) {
					//Case if it has only: right child
					if (prevNode->right_child == rootPtr)
						prevNode->right_child = rootPtr->right_child;
					else
						prevNode->left_child = rootPtr->right_child;
				} else {
					//Case if it has two childs;
					int min_val = minBST(rootPtr->right_child);
					rootPtr->data = min_val;
					return deleteBSTNode(rootPtr->right_child, rootPtr, min_val);
				}

				cout << "node with value: "<< nodeVal <<" had been deleted" << endl;
				delete rootPtr;
			} else if (rootPtr->data > nodeVal) 
				deleteBSTNode(rootPtr->left_child, rootPtr, nodeVal);
			else
				deleteBSTNode(rootPtr->right_child, rootPtr, nodeVal);
		}
};

int main() {
	BST bt;
	bt.insertNode(10);	
	bt.insertNode(7);	
	bt.insertNode(9);	
	bt.insertNode(15);	
	bt.insertNode(16);	
	
	cout << "printInorder():\t";
	bt.printInorder(bt.getRoot());

	cout << "\nisBST(): " << (bt.isBST(bt.getRoot(),  INT_MIN, INT_MAX)  == true? "true":"false") << endl;

	cout << "\nisBST_pre_order(): " << (bt.isBST_pre_order(bt.getRoot(), bt.getRoot()->data, true) == true? "true":"false") << endl;

	bt.deleteBSTNode(bt.getRoot(), bt.getRoot(),  10); 

	cout << "printInorder():\t";
	bt.printInorder(bt.getRoot());
	return 1;
}	
