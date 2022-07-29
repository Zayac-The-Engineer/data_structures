#include "Stack.h"
#include "Node.h"

struct Stack {
    Node *top;
};

Stack *stcreate() {
    return calloc(1, sizeof(Stack));
}

void stdestroy(Stack *self) {
    while (self->top != NULL)
        stpop(self);
    free(self);
}

void stpush (Stack *self, void *content) {
    Node *n = ncreate();
    nset_content(n, content);
    nset_next(n, self->top);
    self->top = n;
}

void *stpop(Stack *self) {
    void *content = nget_content(self->top);
    Node *buf = nget_next(self->top);
    ndestroy(self->top);
    self->top = buf;
    return content;
}

void *stpeek(Stack *self) {
    return nget_content(self->top);
}
