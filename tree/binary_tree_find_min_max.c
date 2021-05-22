#include<stdio.h>
#include<stdlib.h>

struct BSTNode {
	int data;
	struct BSTNode * left_child;
	struct BSTNode * right_child;
};

/**
* creates individual node to be inserted in the BST
* @param data the value for the node (BSTNode.data)
* @return ptr of new BSTNode
*/
struct BSTNode * create_node(int data) {
	printf("creating node with value: %d\n", data);
	struct BSTNode * BSTNode = (struct BSTNode *) malloc(sizeof(struct BSTNode));
	BSTNode->data = data;
	BSTNode->left_child = NULL;
	BSTNode->right_child = NULL;
	return BSTNode;
}

/**
* appends a node into the BST
* @param rootPtr root ptr of BST or BSST (sub tree) 
* @param new_node appending node's ptr
* @return new_node
*/
struct BSTNode * addNode(struct BSTNode * rootPtr, struct BSTNode * new_node) {
	if (rootPtr == NULL) {
		rootPtr = new_node;
	} else if (new_node->data <= rootPtr->data) {
		rootPtr->left_child =  addNode(rootPtr->left_child, new_node);
	} else {
		rootPtr->right_child = addNode(rootPtr->right_child, new_node);
	}
	
	return rootPtr;
}

/**
* print the BST
* @param root ptr of BST/BSST
*/
void printBST(struct BSTNode * rootPtr) {
	if (rootPtr == NULL) return;

	printBST(rootPtr->left_child);
	printf("%d\t", rootPtr->data);
	printBST(rootPtr->right_child);
}

/**
* find min and max of BST
* @param max bool, default false
* @param root pts of BST/BSST
* @return int the min/max
*/
int min_max_BST(int max, struct BSTNode * rootPtr) {

	if (max == 1 && rootPtr->right_child != NULL) {
		return min_max_BST(max, rootPtr->right_child);
	} else if (max == 0 && rootPtr->left_child != NULL) {
		return min_max_BST(max, rootPtr->left_child);
	}

	return rootPtr->data;
}

void main() {
	struct BSTNode * root = NULL;

	root = addNode(root, create_node(10));
	addNode(root, create_node(20));
	addNode(root, create_node(29));
	addNode(root, create_node(9));
	addNode(root, create_node(80));
	addNode(root, create_node(99));

	printBST(root);

	printf("\nmin: %d, max: %d\n", min_max_BST(0, root), min_max_BST(1,root));
}
