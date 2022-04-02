#include <stdlib.h>
#include "btree.h"
#include "/home/antonio/include/stack.h"
#include "/home/antonio/include/queue.h"

struct node {
	Item value;
	struct node *left;
	struct node *right;
};

BTree newTree() {
	BTree t = malloc(sizeof(struct node));
	t = NULL;
	return t;
}

BTree buildTree(BTree sx, BTree dx, Item item) {
	BTree t = malloc(sizeof(struct node));
	t->left = sx;
	t->right = dx;
	t->value = item;
}

int isEmptyTree(BTree t) {
	if(t == NULL)
		return 1;
	else
		return 0;
}

int isLeaf(BTree l) {
	if(l->right == NULL && l->left == NULL)
		return 1;
	else
		return 0;
}

void preOrder(BTree t) {
	if(isEmptyTree(t))
		return;
	else {
		outputItem(t->value);
		preOrder(t->left);
		preOrder(t->right);
	}
}

void postOrder(BTree t) {
	if(isEmptyTree(t))
		return;
	else {
		postOrder(t->left);
		postOrder(t->right);
		outputItem(t->value);
	}
}

void inOrder(BTree t) {
	if(isEmptyTree(t))
		return;
	else {
		preOrder(t->left);
		outputItem(t->value);
		preOrder(t->right);
	}
}

int treeHigh(BTree t) {
	if(isEmptyTree(t) || isLeaf(t))
		return 0;

	int hdx = treeHigh(t->right) + 1;
	int hsx = treeHigh(t->left)  + 1;

	if(hdx > hsx)
		return hdx;
	else
		return hsx;
}

int nNodes(BTree t) {
	if(isEmptyTree(t))
		return 0;
	else if(isLeaf(t))
		return 1;

	return 1 + nNodes(t->right) + nNodes(t->left);
}

void itPreOrder(BTree t) {
	if(isEmptyTree(t))
		return;

	Stack s = newStack();

	push(s, t);

	for(; !isEmptyStack(s); t = top(s)) {
		if(isEmptyTree(t))
			continue;
		outputItem(t->value);
		pop(s);
		if(isLeaf(t))
			continue;
		push(s, t->right);
		push(s, t->left);
	}
}

void byLevel(BTree t) {
	if(isEmptyTree(t))
		return;

	Queue q = newQueue();

	enqueue(q, t);

	while(!isEmptyQueue(q)) {
	  t = dequeue(q);
		outputItem(t->value);

		if(!isEmptyTree(t->left))
			enqueue(q, t->left);
		if(!isEmptyTree(t->right))
			enqueue(q, t->right);
	}
}

Item max(BTree t) {
	if(isEmptyTree(t))
		return NULL;

	Item s = max(t->left);
	Item d = max(t->right);
	Item i = t->value;
	

	if(((d == NULL) && (s == NULL)) || ((compItem(t->value, d) >= 0) && (compItem(t->value, s) >= 0)))
		return t->value;
	else if((compItem(t->value, d) < 0) && (s == NULL || (compItem(d, s) >= 0)))
		return d;
	else if((compItem(t->value, s) < 0) && (d == NULL || (compItem(d, s) < 0)))
		return s;
}

int eqBTree(BTree t1, BTree t2) {
	if(isEmptyTree(t1) && isEmptyTree(t2))
		return 1;
	if(isEmptyTree(t1) && !isEmptyTree(t2))
		return 0;
	if(!isEmptyTree(t1) && isEmptyTree(t2))
		return 0;
	if(compItem(t1->value, t2->value) == 0)
		return eqBTree(t1->left, t2->left) * eqBTree(t1->right, t2->right);
	else
		return 0;
}

void eqLevelList(BTree t, int k, List *list) {
	if(isEmptyTree(t))
		return;
	else if(k % 2 == 0)
		addListTail(*list, t->value);
	eqLevelList(t->left, k+1, list);
	eqLevelList(t->right, k+1, list);
}

List eqLevel(BTree t) {
	List list = newList();

	eqLevelList(t, 0, &list);

	return list;
}

void itInOrder(BTree t) {
	Stack p = newStack();

	while(1) {
		while(t != NULL) {
			push(p, t);
			t = t->left;
		}

	if(isEmptyStack(p))
		break;

	t = top(p);
	pop(p);
	outputItem(t->value);

	t = t->right;
	}
}
