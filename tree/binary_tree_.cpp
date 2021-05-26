#include<iostream>
using namespace std;

class BST {
	private:
		struct BSTNode {
			int data;
			BSTNode *left_child;
			BSTNode *right_child;
		};

		BSTNode *root = NULL;
	
	public:
		void appendTree(int data) {
			appendTree(data, root);
		}

		BSTNode * appendTree(int data, BSTNode *root_ptr) {
			
			if (root_ptr == NULL) {
				BSTNode *new_node = new BSTNode();
				new_node->data = data;
				new_node->left_child = new_node->right_child = NULL;

				if (root == NULL)
					root = new_node;
				printf("inserting: %d\n", data);
				return new_node;
			} else if (data <= root_ptr->data)
				 root_ptr->left_child = appendTree(data, root_ptr->left_child);
			else
				 root_ptr->right_child = appendTree(data, root_ptr->right_child);
		
			return root_ptr;	
		}
	
		void printTree(BSTNode *root_ptr = NULL) {
			if (root_ptr == NULL) root_ptr = root;
			if (root_ptr == NULL) return;
 
			if (root_ptr->left_child != NULL)
				printTree(root_ptr->left_child);

			cout << root_ptr->data << "\t";

			if (root_ptr->right_child != NULL)
				printTree(root_ptr->right_child);
		} 

		int minBST(BSTNode * root_ptr) {
			if (root_ptr->left_child != NULL)
				 return minBST(root_ptr->left_child);
			return root_ptr->data;
		}
	
		BSTNode * search(int data, BSTNode * root_ptr) {
			if (root_ptr == NULL) return NULL;
	
			if (data < root_ptr->data)
				return search(data, root_ptr->left_child);
			else if (data > root_ptr->data)
				return search(data, root_ptr->right_child);
			else
				return root_ptr;

		}

		void getSuccessor(int data) {
			BSTNode * get_node = search(data, root);
			int min_ = data;

			if (get_node->right_child != NULL)
				min_ = minBST(get_node->right_child);
			else {
				BSTNode *successor = NULL, *ancestor = root;
				while( ancestor != get_node) {
					if (data < ancestor->data) {
						successor = ancestor;
						ancestor = ancestor->left_child;
					} else ancestor = ancestor->right_child;
				}
				
				min_ = successor->data;
			}

			printf("\nSuccessor: %d\n", min_);
		}
};


int main() {
	BST tree_1;
	tree_1.appendTree(15);
	tree_1.appendTree(9);
	tree_1.appendTree(10);
	tree_1.appendTree(20);
	tree_1.appendTree(17);
	tree_1.appendTree(25);
	tree_1.appendTree(12);
	tree_1.appendTree(11);
	tree_1.printTree();
	int x;
	while (true) {
		cout << "\nFind Successor: ";
		cin >> x;
		tree_1.getSuccessor(x);
	}
	return 1;
}
