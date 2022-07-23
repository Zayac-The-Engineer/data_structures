#include "DNode.h"
#include "Node.h"

struct DNode {
    Node *self;
    DNode *prev;
};

DNode *dncreate() {
    DNode *self = (DNode *)calloc(1, sizeof (DNode));
    self->self = ncreate();
    return self;
}

void dndestroy(DNode *self) {
    ndestroy(self->self);
    free(self);
}

void *dnget_content(DNode *self) {
    return nget_content(self->self);
}

void dnset_content(DNode *self, void *content) {
    nset_content(self->self, content);
}

DNode *dnget_next(DNode *self) {
    return (DNode *)nget_next(self->self);
}

void dnset_next(DNode *self, DNode *next) {
    nset_next(self->self, (Node *)next);
}

DNode *dnget_prev(DNode *self) {
    return self->prev;
}

void dnset_prev(DNode *self, DNode *prev) {
    self->prev = prev;
}
