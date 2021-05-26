#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//Basic BST node structure
typedef struct BSTNode {
	int data;
	struct BSTNode *left_child;
	struct BSTNode *right_child;
} BSTNode;

/**
* append node into BST
* @param rootPtr BST root pointer
* @param data value for the node
* @return root pointer of BST
*/
BSTNode * appendBSTNode(BSTNode * rootPtr, int data) {
	if (rootPtr == NULL) {
		BSTNode *new_node = (BSTNode *)
			malloc(sizeof(BSTNode));
		new_node->data = data;
		new_node->left_child = new_node->right_child = NULL;
		rootPtr = new_node;
		printf("Insert node: %d\n", data);
	} else if (data <= rootPtr->data)
		rootPtr->left_child = appendBSTNode(rootPtr->left_child, data);
	else
		rootPtr->right_child = appendBSTNode(rootPtr->right_child, data);

	return rootPtr;
}

/**
* print inorder BST
* @param rootPtr BST root pointer
*/
void printInorderBST(BSTNode * rootPtr) {
	if (rootPtr == NULL) return;
	
	printInorderBST(rootPtr->left_child);
	printf("%d\t", rootPtr->data);
	printInorderBST(rootPtr->right_child);
}

/** find MIN of BST
* @param rootPtr given root pointer of BST
* @return min
*/
int minBST(BSTNode * rootPtr) {
	if (rootPtr->left_child != NULL)
		return minBST(rootPtr->left_child);
	
	return rootPtr->data;
}
int maxBST(BSTNode * rootPtr) {
	if (rootPtr->right_child != NULL)
		return minBST(rootPtr->right_child);
	
	return rootPtr->data;
}


/** 
* find Succsor of BST complex: o(n)
* @param rootPtr root pointer of BST 
* @param nodeValue node val to find successor
* @return succsor
*/
int find_successor(BSTNode * rootPtr, int data, int prev) {
	if (rootPtr == NULL) return data;

	find_successor(rootPtr->left_child, data, rootPtr->data);
	
	if (prev == data) {
		return rootPtr->data;
	}

	find_successor(rootPtr->right_child, data, rootPtr->data);
	
}

/**
* find Succsor of BST complex: o(h)
* @param rootPtr root pointer of BST 
* @param parent_node parent node of the subtree (root node should be passed by default)
* @param nodeValue node val to find successor
* @return succsor
*/
int find_successor_h(BSTNode * rootPtr, int data, BSTNode *parent_node) {
	if (rootPtr == NULL) return data;
	int rt;

	if (data < rootPtr->data)
		rt = find_successor_h(rootPtr->left_child, data, rootPtr);
	else if (data > rootPtr->data)
		rt = find_successor_h(rootPtr->right_child, data, rootPtr);
	else {
		if (rootPtr->right_child != NULL)
			return minBST(rootPtr->right_child);
		else if (rootPtr != parent_node)
			return INT_MIN;	
		else
			return data;
	}

		if (rt == INT_MIN)
			return INT_MAX;
		
		if (rt == INT_MAX)
			return parent_node->data;
}

int main() {
	BSTNode * root_ptr = NULL;

	root_ptr = appendBSTNode(root_ptr, 90);
	appendBSTNode(root_ptr, 50);
	appendBSTNode(root_ptr, 60);
	appendBSTNode(root_ptr, 70);
	appendBSTNode(root_ptr, 55);

	printInorderBST(root_ptr);
	printf("\nsuccrssord o(h): %d\n", find_successor_h(root_ptr,50, root_ptr));
	return 1;
}

