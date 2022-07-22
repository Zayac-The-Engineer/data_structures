#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"
#include <stdlib.h>

typedef struct LinkedList LinkedList;

LinkedList *llcreate();
void lldestroy(LinkedList *self);
void llpush(LinkedList *self, void *content);
Node *llpop(LinkedList *self);
Node *llget_head(LinkedList *self);

#endif // LINKEDLIST_H_
