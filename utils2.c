#include <string.h>
#include <stdlib.h>

void swap(char *str1, char *str2) {
	char *temp = malloc(strlen(str2)*sizeof(char));
	strcpy(temp,str2);
	strncpy(str2,str1,strlen(str1));
	strncpy(str1,temp,strlen(temp));
}

void swap_int(int a, int b) {
	int temp = b;
	b = a;
	a = temp;
}
