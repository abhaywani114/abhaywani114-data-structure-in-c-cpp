#include <stdio.h>
#include <stdlib.h>

// defining node structure
struct node {
	int data;
	struct node * next;
};

//function prototyping
struct node * insert_node(struct node *);
void print_node(struct node *);
void reversing_node_recursing(struct node *);

struct node *head = NULL;
int main() {
	int node_no;
	
	printf("How many nodes you want to create> ");
	scanf("%d", &node_no);

	for(int i = 0; i < node_no; i++)
		head = insert_node(head);
	
	print_node(head);	

	printf("\nReversing using an recursive algorithm\n");
	reversing_node_recursing(head);
	print_node(head);
	return 1;
}

struct node * insert_node(struct node * head) {
	int value;
	
	printf("Enter some value for the node> ");
	scanf("%d", &value);

	struct node * new_node, *temp_head_node = head;
	new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = value;
	new_node->next = NULL;

	if (head == NULL)
		return new_node;
	else {
		
		while(temp_head_node->next != NULL)
			temp_head_node = temp_head_node->next;
		temp_head_node->next = new_node;

		return head;
	}
}

void print_node(struct node * head) {
	printf("\nPrinting Linked List> ");

	while(head != NULL) {
		printf("\t%d", head->data);
		head = head->next;
	}
	
	printf("\n");
}

void reversing_node_recursing(struct node * current_node) {
	if (current_node->next == NULL) {
		head = current_node;
		return;
	}

	reversing_node_recursing(current_node->next);
	current_node->next->next = current_node;
	current_node->next = NULL;
}
