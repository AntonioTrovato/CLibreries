#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "list.h"

struct node {
	Item value;
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

Item removeHead(List l) {//aggiungi controllo isEmpty
	if(isEmptyList(l) == 1) {
		fprintf(stderr, "Lista vuota\n");
		return NULL;
	}
	Item i;
	struct node *t = l->head;
	l->head = t->next;// oppure (*(*l).head).next;
	i = t->value;
	free(t);
	l->size--;
	return i;
}

Item getHead(List l) {//aggiungi controllo isEmpty
	if(isEmptyList(l) == 1) {
		fprintf(stderr, "Lista vuota\n");
		return NULL;
	}

	return l->head->value;
}

int listSize(List l) {
	return l->size;
}

void printList(List l) {
	if(l == NULL);
	else {
		struct node *p;
		for(p = l->head; p != NULL; p = p->next)
			outputItem(p->value);
	}
}

struct node *my_min(struct node *p) {
	struct node *min = p;

	for(p = p->next; p != NULL; p = p->next)
		if(compItem(min->value, p->value) > 0)
			min = p;

	return min;
}

void selectionSortList(List l) {
	struct node *p, *m;

	for(p = l->head; p!=NULL; p = p->next) {
		m = my_min(p);
		swap(&(p->value),&(m->value));
	}
}

int searchItem(List l, Item i) {
	int q = 0;
	struct node *p;

	for(p = l->head; p != NULL; p = p->next) {
		if(compItem(p->value, i) == 0)
			return q;
		q++;
	}

	return -1;
}

Item removeItem(List l, Item item) {
	struct node *prev, *p;
	Item i;

	if(isEmptyList(l) == 1) {
		fprintf(stderr,"Lista vuota\n");
		return NULL;
	}

	for(p = l->head; p != NULL; prev = p, p = p->next) {
		if(compItem(p->value, item) == 0) {
			if(p == l->head)
				return removeHead(l);
			else {
				prev->next = p->next;
				i = p->value;
				free(p);
				l->size--;
				return i;
			}
		}
	}

	return NULL;
}

Item removeItemPos(List l, int pos) {
	int j = 0;
	Item i;

	if(isEmptyList(l) == 1) {
		fprintf(stderr,"Lista vuota\n");
		return NULL;
	}

	if(pos < 0 || pos > l->size) {
		fprintf(stderr,"Posizione incorretta\n");
		return NULL;
	}

	struct node *prev, *p;

	for(p = l->head; p != NULL; prev = p, p = p->next, j++) {
		if(j == pos) {
			if(pos == 0)
				return removeHead(l);
			else {
				prev->next = p->next;
				i = p->value;
				free(p);
				l->size--;
				return i;
			}
		}
	}

	return NULL;
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

int reverseList(List list) {
	if(isEmptyList(list) == 1) {
		fprintf(stderr, "Lista vuota\n");
		return 0;
	}
	else {
		struct node *prev, *p, *temp;
		prev = list->head;
		for(p = prev->next, prev->next = NULL; p->next != NULL; prev = p, p = temp) {
			temp = p->next;
			p->next = prev;
		}
		p->next = prev;
		list->head = p;
		return 1;
	}
}

List cloneList(List list) {
	List clone = newList();
	struct node *p;

	for (p = list->head; p != NULL; p = p->next) {
		Item item=cloneItem(p->value);
		addListTail(clone,item);
	}

	return clone;
}
