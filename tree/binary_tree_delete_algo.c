#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct BSTNode {
	int data;
	struct BSTNode * left_child;
	struct BSTNode * right_child;
} BSTNode;

/**
* insert a node into binary search tree
* @param rootPtr root pointer of the BST
* @param data the value for the new node'
* @return rootPtr root pointer of the BST
*/
BSTNode * insertNode(BSTNode * rootPtr, int data) {
	if (rootPtr == NULL) {
		BSTNode *new_node = (BSTNode *) malloc(sizeof(BSTNode));
		new_node->data = data;
		new_node->right_child = new_node->left_child = NULL;
		rootPtr = new_node;
		printf("inserting node: %d\n", data);
	} else if (data <= rootPtr->data) {
		rootPtr->left_child = insertNode(rootPtr->left_child, data);
	} else if (data > rootPtr->data) {
		rootPtr->right_child = insertNode(rootPtr->right_child, data);
	}

	return rootPtr;
}

void printBST(BSTNode * rootPtr) {
	if (rootPtr == NULL) return;

	printBST(rootPtr->left_child);
	printf("%d\t", rootPtr->data);
	printBST(rootPtr->right_child);
}

int BSTMin(BSTNode * rootPtr) {
	if (rootPtr->left_child != NULL)
		return BSTMin(rootPtr->left_child);

	return rootPtr->data;
}

// delete an node the the BST
// @param root : root pointer of BST
// @param nodeVal : what to delete?
// @return root pointer
BSTNode * deleteBSTNode(BSTNode * root, int nodeVal) {
	if (nodeVal < root->data)
		root->left_child = deleteBSTNode(root->left_child, nodeVal);
	else if (nodeVal > root->data)
		root->right_child = deleteBSTNode(root->right_child, nodeVal);
	else {

		if (root->left_child == NULL && root->right_child == NULL) {
			free(root);
			root = NULL;
		} else if (root->right_child == NULL || root->left_child == NULL) {
			BSTNode *temp_node = root;
			root = (root->right_child == NULL) ?  root->left_child:root->right_child;
			free(temp_node);
		} else {
			int minVal = BSTMin(root->right_child);
			root->data = minVal;
			root->right_child = deleteBSTNode(root->right_child, minVal);
		}	
	
	}
	
	return root;
}

//is tree BST using range check algorithm
int isBST(BSTNode * root, int max_val, int min_val) {
	if (root == NULL) return 1 == 1;

	return (root->data < max_val && root->data > min_val
			&& isBST(root->left_child, root->data, min_val)
			&& isBST(root->right_child, max_val, root->data));
}

int main() {
	BSTNode *root_ptr = NULL;
	root_ptr = insertNode(root_ptr, 10);
	root_ptr = insertNode(root_ptr, 9);
	root_ptr = insertNode(root_ptr, 15);
	root_ptr = insertNode(root_ptr, 7);
	root_ptr = insertNode(root_ptr, 16);
	root_ptr = insertNode(root_ptr, 14);

	printBST(root_ptr);
	printf("\n");	
	root_ptr  = deleteBSTNode(root_ptr, 10);
	printBST(root_ptr);
	
	printf("\nIsBst: %s\1", (
		 isBST(root_ptr, INT_MAX, INT_MIN) == 1 ? "Yes":"No"));
}
