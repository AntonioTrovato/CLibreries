#include <stdlib.h>
#include <stdlib.h>

#include "utils.h"
#include "list.h"
#include "item.h"

struct node {
	Item item;
	struct node *next;
};

struct list {
	int size;
	struct node *head;
};

List newList() {
	List l = malloc(sizeof(struct list));

	l->size = 0;
	l->head = NULL;

	return l;
}

int isEmptyList(List l) {
	if(l->size == 0)
		return 1;
	else
		return 0;
}

void addHead(List l, Item i) {
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	new_node->value = i;
	new_node->next = l->head;
	l->head = new_node;
	l->size++;
}

int addListItem(List list, Item item, int pos) {
	if(pos < 0 || pos > list->size) {
		fprintf(stderr,"Posizione incorretta\n");
		return 0;
	}else if(pos == 0) {
		addHead(list, item);
		return 1;
	}

	int i = 0;
	struct node *p, *n = malloc(sizeof(struct node));

	for(p = list->head; i < pos-1; p = p->next, i++);

	n->next = p->next;
	p->next = n;
	n->value = item;
	list->size++;

	return 1;
}

int addListTail(List list, Item item) {
	return addListItem(list, item, list->size);
}

void printListRic(struct node *p) {
	if(p == NULL);
	else {
		outputItem(p->item);
		printListRic(p->next);
	}
}

void printList(List list) {
	printListRic(list->head);
}

int searchItemRic(struct node *p, Item item, int i) {
	if(p == NULL)
		return -1;
	else if(!cmpItem(p->item, item))
		return i;
	else
		return searchItemRIc(p->next, item, i+1);
}

int searchItem(List list, Item item) {
	return searchItemRic(list->head, item, 0);
}

int itemOccurrenceRic(struct node *p, Item item, int i) {
	if(p == NULL)
		return i;
	else if(!cmpItem(p->item, item))
		return itemOccurrenceRic(p->next, item, i+1);
	else
		return itemOccurrenceRic(p->next, item, i);
}

int itemOccurrence(List list, Item item) {
	return itemOccurrenceRic(p->head, item, 0);
}

void freeListRic(struct node *p) {
	freeListRic(p->next);
	free(p);
}

void freeList(List list) {
	freeListRic(list->head);
}

List cloneList(List list) {
	List clone = newList();

	if(list->size == 0)
		return NULL;
	return cloneListRic(clone, list->head, 1);
}

List cloneListRic(List clone, struct node *p, int i) {
	if(isEmptyList(list))
		return NULL;

	if(i%2 == 0) {
		if(p == NULL)
			return clone;
		else {
			Item item = cloneItem(p->item);
			addListTail(clone, item);
			return cloneListRic(clone, p->next, i+1);
		}
		return clone;
	}

	return cloneListRic(p->next, i+1);
}
