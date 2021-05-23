#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode {
	int data;
	struct BSTNode * left_child;
	struct BSTNode * right_child;
} BSTNode;

/**
*	Queue node str
*/
typedef struct queueNode {
	BSTNode * BSTNode;
	struct queueNode * next;
} queueNode;

/**
* create a BSTNode and assign data to it
* @param data the value to be assigned to BSTNode.
* @return new BSTNode's ptr
*/

BSTNode * createNode(int data) {
	printf("CreateNode(%d)\n", data);

	BSTNode * new_node = (BSTNode *) malloc(sizeof(BSTNode));
	
	new_node->data = data;
	new_node->left_child = NULL;
	new_node->right_child = NULL;
	
	return new_node;
}

/**
* appends new node to the binary search tree
* @param rootPtr root pointer of the BST
* @param newNodePtr new BST node's pointer
* @return rootPtr
*/
BSTNode * appendTree(BSTNode * rootPtr, BSTNode * newNodePtr) {
	if (rootPtr == NULL)
		rootPtr = newNodePtr;
	else if (newNodePtr->data <= rootPtr->data)
		rootPtr->left_child = appendTree(rootPtr->left_child,newNodePtr);
	else
		rootPtr->right_child = appendTree(rootPtr->right_child, newNodePtr);

	return rootPtr;
}

/**
*	Traverse the binary search tree in depth-first mode (Preorder)
*	@param rootPtr root pointer of the BST
*/
void print_preorder(BSTNode * rootPtr) {
	if (rootPtr == NULL) return;

	printf("%d\t", rootPtr->data);
	print_preorder(rootPtr->left_child);	
	print_preorder(rootPtr->right_child);	
}

/**
*	Traverse the binary search tree in depth-first mode (Inorder)
*	@param rootPtr root pointer of the BST
*/
void print_inorder(BSTNode * rootPtr) {
	if (rootPtr == NULL) return;

	print_inorder(rootPtr->left_child);	
	printf("%d\t", rootPtr->data);
	print_inorder(rootPtr->right_child);	
}

/**
*	Traverse the binary search tree in depth-first mode (Postorder)
*	@param rootPtr root pointer of the BST
*/
void print_postorder(BSTNode * rootPtr) {
	if (rootPtr == NULL) return;

	print_postorder(rootPtr->left_child);	
	print_postorder(rootPtr->right_child);	
	printf("%d\t", rootPtr->data);
}

/**
* enqueue binary search tree node into the queue
* @param tail reffrence of tail of the queue
* @param front reffrence of front of the queue
* @param BSN pointer of binary search tree
*/
void enqueue_BSTNode(queueNode ** tail, queueNode ** front, BSTNode * BSN) {
	if (BSN == NULL) return;

	queueNode * new_queue_node = (queueNode *) malloc(sizeof(queueNode));
	new_queue_node->next = NULL;
	new_queue_node->BSTNode = BSN;

	if (*tail != NULL)
		(*tail)->next  = new_queue_node;

	if (*front == NULL)
		*front = new_queue_node;
	
	*tail = new_queue_node;
}

/**
* dequeue binary search tree node from the queue
* @param tail reffrence of tail of the queue
* @param front reffrence of front of the queue
* @return BST node ptr of binary search tree
*/
BSTNode * dequeue_BSTNode(queueNode ** tail, queueNode ** front) {
	if (*front != NULL) {
		 BSTNode *return_node  = (*front)->BSTNode;
		 queueNode *temp_node = *front;

	     *front = (*front)->next;
		
		if (*tail == temp_node) {
			*tail = NULL;
		}
		
		free(temp_node);
		
		return return_node;
	} else {
		printf("The queue is empty");
	}
}

/**
* Test if the queue is empty or not
* @param tail of the queue
* @return true if queue is empty 
*/
int isQueueEmpty_BTSNode(queueNode * tail) {
	return tail == NULL;
}

/**
* Printing in level order traversal mode
* @param rootPtr root pointer of binary search tree
* @param LR bool if left-right or right-left order
*/
void print_BST_BF_MODE(BSTNode * rootPtr, int LR) {
	if (rootPtr == NULL) return; 

	queueNode *tail = NULL, *front = NULL;
	enqueue_BSTNode(&tail, &front, rootPtr); 

	while(!isQueueEmpty_BTSNode(tail)) {
		BSTNode * que_node = dequeue_BSTNode(&tail, &front);

		printf("%d\t", que_node->data);
		if (LR == 1) {	
			enqueue_BSTNode(&tail, &front, que_node->left_child); 
			enqueue_BSTNode(&tail, &front, que_node->right_child); 
		} else {
			enqueue_BSTNode(&tail, &front, que_node->right_child); 
			enqueue_BSTNode(&tail, &front, que_node->left_child); 
		}
	}
	printf("\n");
}

void main() {
	BSTNode * root = NULL;

	root = appendTree(root, createNode(10));
	appendTree(root, createNode(9));
	appendTree(root, createNode(11));
	appendTree(root, createNode(8));

	printf("\nDepth first mode:\n");
	printf("print_preorder():\t");
	print_preorder(root);

	printf("\nprint_inorder():\t");
	print_inorder(root);

	printf("\nprint_postorder():\t");
	print_postorder(root);

	printf("\n\nBreadth First mode (level order traversal):\n");
	printf("print_BST_BF_MODE(LR):\t");
	print_BST_BF_MODE(root, 1);
	
	printf("print_BST_BF_MODE(RL):\t");
	print_BST_BF_MODE(root, 0);
}
