#include "item.h"

typedef struct list *List;

List newList();
int isEmptyList(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int listSize(List);
void printList(List);
void selectionSortList(List);
int searchItem(List, Item);
Item removeItem(List, Item);
Item removeItemPos(List, int);
int addListItem(List, Item, int);
int addListTail(List, Item);
int reverseList(List);
List cloneList(List);
