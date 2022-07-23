#include "Node.h"

struct Node {
    void *content;
    Node *next;
};

Node *ncreate() {
    return (Node *)calloc(1, sizeof (Node));
}

void ndestroy(Node *self) {
    free(self);
}

void *nget_content(Node *self) {
    return self->content;
}

void nset_content(Node *self, void *content) {
    self->content = content;
}

Node *nget_next(Node *self) {
    return self->next;
}

void nset_next(Node *self, Node *next) {
    self->next = next;
}
