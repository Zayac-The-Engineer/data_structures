#include "Deque.h"
#include "DNode.h"
#include "Node.h"

struct Deque {
    DNode *head;
    DNode *tail;
};

Deque *dqcreate() {
    return (Deque *)calloc(1, sizeof (Deque));
}

void dqdestroy(Deque *self) {
    DNode* dn = self->head;
    while (dn != NULL) {
        DNode* next = dnget_next(dn);
        dndestroy(dn);
        dn = next;
    }
    free(self);
}

void dqpush_back(Deque *self, void *content) {
    DNode *dn = dncreate();
    dnset_content(dn, content);

    if (self->tail == NULL) {
        self->head = dn;
    } else {
        dnset_prev(dn, self->tail);
        dnset_next(self->tail, dn);
    }
    self->tail = dn;
}

void *dqpop_back(Deque *self) {
    void *content = dnget_content(self->tail);
    if (dnget_prev(self->tail) == NULL) {
        dndestroy(self->tail);
        self->tail = NULL;
        self->head = NULL;
    } else {
        self->tail = dnget_prev(self->tail);
        dndestroy(dnget_next(self->tail));
    }
    return content;
}

void dqpush_front(Deque *self, void *content) {
    DNode *dn = dncreate();
    dnset_content(dn, content);

    if (self->head == NULL) {
        self->tail = dn;
    } else {
    dnset_next(dn, self->head);
    dnset_prev(self->head, dn);
    }
    self->head = dn;
}

void *dqpop_front(Deque *self) {
    void *content = dnget_content(self->head);
    if (dnget_next(self->head) == NULL) {
        dndestroy(self->head);
        self->tail = NULL;
        self->head = NULL;
    } else {
        self->head = dnget_next(self->head);
        dndestroy(dnget_prev(self->head));
    }
    return content;
}
