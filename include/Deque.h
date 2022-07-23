#ifndef DEQUE_H_
#define DEQUE_H_

#include "DNode.h"
#include <stdlib.h>

typedef struct Deque Deque;

Deque *dqcreate();
void dqdestroy(Deque *self);

void dqpush_back(Deque *self, void *content);
void *dqpop_back(Deque *self);

void dqpush_front(Deque *self, void *content);
void *dqpop_front(Deque *self);

#endif // DEQUE_H_
