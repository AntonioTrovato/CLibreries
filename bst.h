#include "/home/antonio/include/item.h"
#include "list.h"

typedef struct node *BST;

BST newBST();
int isEmptyBST(BST);
int isLeaf(BST);
BST getLeft(BST);
BST getRight(BST);
Item getItem(BST);
Item search(BST, Item);
Item min(BST);
Item max(BST);
int insertItem(BST*, Item);
void byLevel(BST);
Item deleteBST(BST*, Item);
int isBalancedBST(BST, int);
void createBalancedBST(BST *, Item *, int);
void byLevelLeaf(BST);
void elCompresi(BST, Item, Item, List *);
void byLevelEq(BST);
void listMax(BST *, List *, Item);
void deleteMax(BST *, List);
