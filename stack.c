#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "stack.h"

struct stack {
	List elements;
};

Stack newStack() {
	Stack newStack = malloc(sizeof(struct stack));

	newStack->elements = newList();

	return newStack;
}

int isEmptyStack(Stack stack) {
	return isEmptyList(stack->elements);
}

int push(Stack stack, Item item) {//con le liste non potrebbe mai fallire
	addHead(stack->elements, item);

	return 1;
}

int pop(Stack stack) {
	return removeHead(stack->elements) != NULL;
}

Item top(Stack stack) {
	return getHead(stack->elements);
}

void printStack(Stack stack) {
	printf("Top: ");
	printList(stack->elements);
}
