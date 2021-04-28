#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char st[100];
	struct node * next;
};

struct node *top = NULL;

int is_stack_empty() {
	return top == NULL;
}

void push_stack(char st[]) {
	struct node * new_node =
		(struct node *) malloc(sizeof(struct node));
	
	strcpy(new_node->st, st);
	new_node->next = NULL;
	
	if (!is_stack_empty())
		new_node->next = top;
		
	top = new_node;
}

void pop_stack() {
	struct node * temp_node = top;
	top = top->next;
	free(temp_node);
}

int get_operand(int * is_valid) {
	int operand;

	while(strcmp(top->st, ",") == 0) {
		pop_stack();
	}
	 
	if (!is_stack_empty()) {
		operand = atoi(top->st); 
		pop_stack();
	} else {
		operand = 0;
		is_valid = 0;
	}

	return operand;
}

void eval_expression(char ch[]) {
	int is_valid = 1, expression_len = strlen(ch), operand_1, operand_2, result;
	char temp_string[100];
	
	for (int i = 0; i < expression_len; i++) {
		if (ch[i] == '+' || ch[i] == '-' || ch[i] == '/' || ch[i] == '*') {
			if (ch[i+1] == ',' || ch[i+1] == '\0') {
				
				//0P 2;	
				if (!is_stack_empty())
					operand_2 = get_operand(&is_valid);
				else
					is_valid = 0;

				//0P 1;	
				if (!is_stack_empty())
					operand_1 = get_operand(&is_valid);
				else
					is_valid = 0;

				if (!is_stack_empty())
					is_valid = 0;
	
				if (ch[i] == '+')
					result = operand_1 + operand_2;

				if (ch[i] == '-')
					result = operand_1 - operand_2;
					
				if (ch[i] == '/')
					result = operand_1 / operand_2;

				if (ch[i] == '*')
					result = operand_1 * operand_2;
				
				sprintf(temp_string, "%d", result);	
				push_stack(temp_string);
			} else {
				if (ch[i] == '-' || ch[i] == '+')
					goto process_number;
				else
					is_valid = 0;
			}

		} else if (ch[i] == '1' || ch[i] == '2' || ch[i] == '3' || ch[i] == '4' || ch[i] == '5' ||
				ch[i] == '6' || ch[i] == '7' || ch[i] == '8' || ch[i] == '9' || ch[i] == '0' ) {
			process_number:
			//getting previous string part
			strcpy(temp_string , (is_stack_empty() ? "":(top->st[0] == ',' ? "":top->st))); // working on this later	

			//adding new character
			strncat(temp_string, &ch[i], 1);

			//pusing to stack
			if (!is_stack_empty())
				if (top->st != ",")
					pop_stack();
	
			push_stack(temp_string);
			//validated if string is not ending
			if (ch[i+1] == '\0')
				is_valid = 0;


		} else if (ch[i] == ',') {
			if (is_stack_empty())
				is_valid = 0;
			else if (top->st == ",")
				is_valid = 0;
			
			push_stack(",");

		} else {

		}
	
		if (is_valid == 0) {
			printf("The expression is not valid\n");
			return;
		}
	}

	printf("The result of eval of postfix expression is: %s\n", top->st);
	
	while(top != NULL)
		pop_stack();
}

int main() {
	char expression[1000];

	printf("Enter a postfix expression> ");
	scanf("%s",&expression);
	eval_expression(expression);
	return 1;
}
