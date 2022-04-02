#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "queue.h"

struct node {
	Item value;
	struct node *left;
	struct node *right;
};

BST newBST() {
	return NULL;
}

int isEmptyBST(BST t) {
	if(t == NULL)
		return 1;
	else
		return 0;
}

int isLeaf(BST t) {
	if(t->left == NULL && t->right == NULL)
		return 1;
	else
		return 0;
}

BST getLeft(BST t) {
	if(isEmptyBST(t))
		return NULL;
	else
		return t->left;
}

BST getRight(BST t) {
	if(isEmptyBST(t))
		return NULL;
	else
		return t->right;
}

Item getItem(BST t) {
	if(isEmptyBST(t))
		return NULL;
	else
		return t->value;
}

Item search(BST t, Item item) {
	if(isEmptyBST(t))
		return NULL;
	else if(!compItem(t->value, item))
		return t->value;
	else if(compItem(t->value, item) > 0)
		search(t->left, item);
	else
		search(t->right, item);
}

Item min(BST t) {
	if(isEmptyBST(t))
		return NULL;
	else if(t->left == NULL)
		return t->value;
	else
		min(t->left);
}

Item max(BST t) {
	if(isEmptyBST(t))
		return NULL;
	else if(t->right == NULL)
		return t->value;
	else
		max(t->right);
}

int insertItem(BST *t, Item item) {
	if((*t) == NULL) {
		BST nt = malloc(sizeof(struct node));
		nt->value = item;
		(*t) = nt;
		return 1;
	}else if(compItem((*t)->value, item) > 0)
		insertItem(&((*t)->left), item);
	else if(compItem((*t)->value, item) < 0)
		insertItem(&((*t)->right), item);
	else return 1;
}

void byLevel(BST t) {
	if(isEmptyBST(t))
		return;

	Queue q = newQueue();

	enqueue(q, t);

	while(!isEmptyQueue(q)) {
	  t = dequeue(q);
		outputItem(t->value);

		if(!isEmptyBST(t->left))
			enqueue(q, t->left);
		if(!isEmptyBST(t->right))
			enqueue(q, t->right);
	}
}

Item deleteBST(BST *tree, Item item)
{
	if(isEmptyBST(*tree))
		return NULL;
	else{
		if(compItem(item, (*tree)->value) < 0)
			return deleteBST(&(*tree)->left, item);
		else if(compItem(item, (*tree)->value) > 0)
			return deleteBST(&(*tree)->right, item);
		else{
			if(isEmptyBST((*tree)->right)){
				BST temp = *tree;
				*tree = (*tree)->left;
				Item returned = temp->value;
				free(temp);
				return returned;
			}
			else if(isEmptyBST((*tree)->left)){
				BST temp = *tree;
				*tree = (*tree)->right;
				Item returned = temp->value;
				free(temp);
				return returned;
			}
			else{
				Item maxItem = max((*tree)->left);
				Item returned = (*tree)->value;
				(*tree)->value = maxItem;
				deleteBST(&(*tree)->left, maxItem);
				return returned;
			}			
		}
	}
}

int treeHigh(BST t) {
	if(isEmptyBST(t) || isLeaf(t))
		return 0;

	int hdx = treeHigh(t->right);
	int hsx = treeHigh(t->left);

	if(hdx > hsx)
		return hdx+1;
	else
		return hsx+1;
}

int isBalancedBST(BST t, int k) {
	if(k < 0) {
		fprintf(stderr, "Parametro numerico errato");
		return 0;
	}
	int hsx = treeHigh(t->left);
	int hdx = treeHigh(t->right);

	if(hsx >= hdx) {
		if((hsx - hdx) <= k)
			return 1;
		else return 0;
	}else {
		if((hdx - hsx) <= k)
			return 1;
		else return 0;
	}

	isBalancedBST(t->left, k);
	isBalancedBST(t->right, k);
}

void createBalancedBST(BST *t, Item a[], int n) {
	if(n == 0)
		return;
	if(n == 1) {
		insertItem(t, *a);
		return;
	}

	insertItem(t, a[n/2]);
	createBalancedBST(t, a, n/2);
	createBalancedBST(t, a+n/2+1, n/2);
}

void byLevelLeaf(BST t) {
	if(isEmptyBST(t))
		return;

	Queue q = newQueue();

	enqueue(q, t);

	while(!isEmptyQueue(q)) {
	  t = dequeue(q);
		if(isLeaf(t))
			outputItem(t->value);

		if(!isEmptyBST(t->left))
			enqueue(q, t->left);
		if(!isEmptyBST(t->right))
			enqueue(q, t->right);
	}
}

void elCompresi(BST t, Item a, Item b, List *list) {
	if(isEmptyBST(t))
		return;
	elCompresi(t->left, a, b, list);
	if((compItem(t->value, b) > 0) && (compItem(t->value, a) < 0)) {
		addListTail(*list, t->value);
		}
	elCompresi(t->right, a, b, list);
}

void byLevelEq(BST t) {
	if(isEmptyBST(t))
		return;
	Queue q = newQueue();

	enqueue(q, t->left);
	enqueue(q, t->right);

	while(!isEmptyQueue(q)) {
	  t = dequeue(q);
		outputItem(t->value);

		if(!isEmptyBST(t->left->left))
			enqueue(q, t->left->left);
		if(!isEmptyBST(t->left->right))
			enqueue(q, t->left->right);
		if(!isEmptyBST(t->right->left))
			enqueue(q, t->right->left);
		if(!isEmptyBST(t->right->right))
			enqueue(q, t->right->right);
	}
}

void listMax(BST *t, List *l, Item m) {
	if(isEmptyBST(*t))
		return;

	if(compItem((*t)->value, m) > 0)
		addListTail(*l, (*t)->value);

	listMax(&((*t)->left), l,  m);
	listMax(&((*t)->right), l, m);
}

void deleteMax(BST *t, List list) {
	if(isEmptyList(list))
		return;

	Item el = removeHead(list);
	deleteBST(t, el);
	deleteMax(t, list);
}
