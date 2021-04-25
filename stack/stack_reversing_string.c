#include<stdio.h>
#include<stdlib.h>

struct node {
	char ch;
	struct node * next;
};

struct node * top = NULL;

int is_stack_empty() {
	return top == NULL;
}

void push_stack(char ch) {
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->ch = ch;
	
	if (top == NULL) {
		new_node->next = NULL;
		top = new_node;
	} else {
		new_node->next = top;
		top = new_node;
	}
}

char pop_stack() {
	struct node * temp = top;
	char ch = '0';

	if (!is_stack_empty()) {
		ch = top->ch;
		top = top->next;
		free(temp);
	}

	return ch;
}

int main() {
	char string[100];
	int i = 0;
	
	printf("Reversing a word using stack\n");
	
	printf("Enter a word> ");
	scanf("%s", &string);

	while(string[i] != '\0') {
		push_stack(string[i]);
		i++;
	}
	
	i = 0;

	while(string[i] != '\0') {
		string[i] = pop_stack();
		i++;
	}

	
	printf("Reverse: %s\n", string);
	return 0;
}
