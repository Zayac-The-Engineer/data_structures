#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct LinkedList LinkedList;

LinkedList *llcreate();
void lldestroy(LinkedList *self);

void llpush(LinkedList *self, void *content);
void *llpop(LinkedList *self);
void *llget(LinkedList *self, size_t idex);

#endif // LINKEDLIST_H_
