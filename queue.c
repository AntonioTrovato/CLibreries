#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "list.h"

struct queue {
	List elements;
};

Queue newQueue() {
	Queue newQueue = malloc(sizeof(struct queue));
	newQueue->elements = newList();
	
	return newQueue;
}

int isEmptyQueue(Queue q) {
	return isEmptyList(q->elements);
} 

int enqueue(Queue q, Item item) {
	return addListTail(q->elements, item);
}

Item dequeue(Queue q) {
	return removeHead(q->elements);
}

void printQueue(Queue q) {
	printf("HEAD: ");
	printList(q->elements);
}
