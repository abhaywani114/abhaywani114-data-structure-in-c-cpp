#include <stdio.h>
#include <string.h>

int main() {
	int i = 0, j;
	char string[100], temp;
	
	printf("Enter a word to reverse> ");
	scanf("%s", &string);
	
	j = strlen(string) - 1 ;

	while (i < j) {
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
		i++;
		j--;
	}

	printf("Reversed Word: %s\n", string);
}
