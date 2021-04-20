#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

/*
	####    List implementation using Array
	1       Display List
	2       Add a new item to end list
	3       Add a new item a position list
	4       Remove a item from list
	5       Exit
*/

int display_menu();
int count_element();
void int_array(); 
void insert_at_end();
void insert_at_pos();
void delete_at_pos();
void display_array();

int arr[SIZE];

void main() {
	int_array();
	while(1) {
		int option = -1;
		option = display_menu();
		
		switch(option) {
			case 1:
				display_array();
			break;
			case 2:
				insert_at_end();
			break;
			case 3:
				insert_at_pos();
			break;
			case 4:
				delete_at_pos();
			break;
			case 5:
				return;
				break;
			case -1:
			default:
				printf("\tPlease enter a valid option");
				break;
		}
	}
}

void int_array() {
	for (int i = 0; i < SIZE; i++) {
		arr[i] = -1;
	}
}

void display_array() {
	printf("\n\tPrinting List:\n\t");

	for (int i = 0; i < SIZE; i++) {
		if (arr[i] == -1)
			break;

		printf("%d\t", arr[i]);
	}

	printf("\n");
}

void insert_at_end() {
	int i = 0;

	while (arr[i] != -1)
		i++;

	printf("\n\tEnter value to the element> ");
	scanf("%d", &arr[i]);
}


void insert_at_pos() {
	int pos, temp, last_element;
	printf("\n\tEnter position where you want to insert> ");
	scanf("%d", &pos);
	printf("\n\tChecking position...");

	if (arr[pos - 1] == -1) {
		printf("\n\tInvalid position...");
		return;
	}
	
	printf("\n\tEnter value to the element> ");
	scanf("%d", &temp);

	//while (arr[last_element] != -1)
	//	last_element++;

	for (int i = pos; i < SIZE; i++) {
		last_element = arr[i];
		arr[i]  = temp;
		temp  = last_element;
		if (temp == -1)
			break;
	}
}

void delete_at_pos() {
	int pos;
	printf("\n\tEnter position where you want delete> ");
	scanf("%d", &pos);
	printf("\n\tChecking position...");

	if (arr[pos] == -1) {
		printf("\n\tInvalid position...");
		return;
	}

	for (int i = pos; i < SIZE; i++) {
		arr[i] = arr[i + 1];
		if (arr[i] == -1) {
			break;
		}
	}
}

int count_element() {
	int  count = 0;
	while (arr[count] != -1)
		count++;
	
	return count;
}

int display_menu() {
	int option = -1;
	printf("\n\n\t#### \tList implementation using Array\n");
	printf("\tItems Count: \t%d\n", count_element());
	printf("\t1 \tDisplay List\n");
	printf("\t2 \tAdd a new item to end list\n");
	printf("\t3 \tAdd a new item a position list\n");
	printf("\t4 \tRemove a item from list\n");
	printf("\t5 \tExit\n");
	printf("\n\tEnter Option> ");
	scanf("%d", &option);
	return option;
}
