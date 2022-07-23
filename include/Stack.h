#ifndef STACK_H_
#define STACK_H_

#include "Node.h"
#include <stdlib.h>

typedef struct Stack Stack;

Stack *stcreate();
void stdestroy(Stack *self);

void stpush(Stack *self, void *content);
void *stpop(Stack *self);
void *stpeek(Stack *self);

#endif // STACK_H_
