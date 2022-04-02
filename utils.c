#include "item.h"

void swap(Item *a, Item *b) {
	Item temp=*b;
	*b=*a;
	*a=temp;
}

int conta_spazi(char *str, int n) {
	char *p = str;
	int i = 0;

	for(; str < p + n; str++)
		if(*str == ' ')
			i++;

	return i;
}
