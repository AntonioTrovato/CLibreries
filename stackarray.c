#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define MAXSTACK 10

struct stack {
	int top;
	Item elements[MAXSTACK];
};

Stack newStack() {
	Stack newStack = malloc(sizeof(struct stack));

	newStack->top = 0;//inizializiamo top a 0, con 10 el. top == 10

	return newStack;
}

int isEmptyStack(Stack stack) {
	return !stack->top;
}

int push(Stack stack, Item item) {//con le liste non potrebbe mai fallire
	if(stack->top == MAXSTACK) {
		fprintf(stderr,"Stack pieno\n");
		return 0;
	}

	stack->elements[stack->top] = item;
	stack->top++;

	return 1;
}

int pop(Stack stack) {
	if(isEmptyStack(stack)) {
		fprintf(stderr,"Stack vuoto\n");
		return 0;
	}

	stack->top--;//tanto l'altro elemento lo sovrascriviamo se vogliamo aggiungerne uno
	return 1;
}

Item top(Stack stack) {
	if(isEmptyStack(stack)) {
		fprintf(stderr,"Stack vuoto\n");
		return NULL;
	}

	return stack->elements[stack->top-1];
}

void printStack(Stack stack) {
	if(isEmptyStack(stack)) {
		fprintf(stderr,"Stack vuoto\n");
		return;
	}

	int i;

	printf("Top: ");
	for(i = stack->top-1; i >= 0; i--)
		outputItem(stack->elements[i]);
}
