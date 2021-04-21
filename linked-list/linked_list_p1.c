#include <stdio.h>
#include <stdlib.h>

/*
	Program Name: Simple Linked List Implementation Using C
	Author: Abrar Ajaz Wani, <abhaywani114@gmail.com
*/

struct node {
	int data;
	struct node * next;
};

// --- FUNCTION PROTOTYPING START -- //

// function to create a node and return it
struct node * create_node(struct node *);

// function to print the linked list
void print_linked_list(struct node *);

// function to delete a node
void delete_node(struct node **);

// count elements
int count_nodes(struct node *);

// function to display menu
int display_menu(struct node *);

// --- FUNCTION PROTOTYPING END -- //

void main() {
	//linked list's head pointer
	struct node * head;

	//init to NULL
	head = NULL;
	
	int option; // for receving menu option input.

	while(1) {
		option = display_menu(head); //display menu

		switch(option) {
			case 1:
				head = create_node(head);
				break;
			case 2:
				print_linked_list(head);
				break;
			case 3:
				delete_node(&head);
				break;
			case 4:
				return;	
			break;
			default:
				printf("\tPlease enter a valid option.");
			break;
		}
	}

}

struct node * create_node(struct node * start) {
	struct node  * new_node;

	//alocating memory
	new_node = (struct node *) malloc(sizeof(struct node));
	
	//setting up values
	printf("\tEnter value for the element> ");
	scanf("%d", & (new_node->data));
	new_node->next = NULL;
	
	//adjusting links if not first element
	if (start != NULL) {
		//creating a head for triversing
		struct node * head = start;
		
		//triverse till end
		while (head->next != NULL)
			head = head->next;
		
		//add the new link
		head->next = new_node;
	}

	//returning head's address.	
	if(start == NULL)
		return new_node;
	else
		return start;
}


void print_linked_list(struct node * head) {
	printf("\n\t###\t Printing linked list\n");
	
	//triversing till end
	while (head != NULL) {
		printf("\t%d", head->data);
		head = head->next;
	}
}


void delete_node(struct node ** start) {
	struct node * head = *start, * prev = NULL;;
	int value_to_del;

	printf("\n\tEnter value of element you want to delete> ");
	scanf("%d", &value_to_del);

	while(head != NULL) {
		// trying to match	
		if (head->data == value_to_del)
			break;

		// moving on
		prev = head;
		head = head->next;
	}

	// if not found
	if (head == NULL) {
		printf("\n\tNode not found!");
		return;
	}

	//first node
	if (prev == NULL)
		*start = head->next;

	//in-between and last node
	if (prev != NULL)
		prev->next = head->next;

	free(head);

}

int count_nodes(struct node * head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}
	
	return count;
}

int display_menu(struct node * head) {
	int option;

	printf("\n\n");
	printf("\t###\t Simple Linked List Implementation Using C");
	printf("\n\t1\tAdd a element to the linked list");
	printf("\n\t2\tPrint the linked list");
	printf("\n\t3\tDelete an element");
	printf("\n\t4\tExit\n");
	printf("\n\tNode Count: %d", count_nodes(head));

    printf("\n\tEnter Option> ");
    scanf("%d", &option);
    return option;	
}
