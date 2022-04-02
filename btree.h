#include "item.h"
#include "/home/antonio/include/list.h"

typedef struct node *BTree;

BTree newTree();
BTree buildTree(BTree, BTree, Item);
int isEmptyTree(BTree);
int isLeaf(BTree);
void preOrder(BTree);
void postOrder(BTree);
void inOrder(BTree);
int treeHigh(BTree);
int nNodes(BTree);
void itPreOrder(BTree);
void byLevel(BTree);
Item max(BTree);
int eqBTree(BTree, BTree);
List eqLevel(BTree);
void itInOrder(BTree);
