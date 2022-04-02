#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

#define MAXQUEUE 100

struct queue {
	Item elements[MAXQUEUE];
	int head;
	int tail;
};

Queue newQueue() {
	Queue q = malloc(sizeof(struct queue));
	q->head = 0;
	q->tail = 0;

	return q;
}

int isEmptyQueue(Queue q) {
	return q->head == q->tail;
}

int enqueue(Queue q, Item item) {
	if((q->tail + 1) % MAXQUEUE == q->head)
		return 0;

	q->elements[q->tail] = item;
	q->tail = (q->tail + 1) % MAXQUEUE;

	return 1;
}

Item dequeue(Queue q) {
	if(isEmptyQueue(q))
		return NULL;

	int a = q->head;
	q->head = (q->head + 1) % MAXQUEUE;

	return q->elements[a];
}

void printQueue(Queue q) {
	int i;

	printf("HEAD: ");
	for(i = q->head; i != q->tail; i = (i + 1) % MAXQUEUE)
		outputItem(q->elements[i]);
}
