#include "Node.h"

struct Node {
    void *content;
    Node *next;
};

Node *ncreate() {
    Node *self = (Node *)calloc(1, sizeof (Node));
    return self;
}

void ndestroy(Node *self) {
    free(self);
}

Node *nget_next(Node *self) {
    return self->next;
}

void nset_next(Node *self, Node *next) {
    self->next = next;
}

void *nget_content(Node *self) {
    return self->content;
}

void nset_content(Node *self, void *content) {
    self->content = content;
}
