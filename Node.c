#include "Node.h"

struct Node {
    void *content;
    Node *next;
};

Node *ncreate() {
    Node *self = (Node *)malloc(sizeof (Node));
    self->content = NULL;
    self->next = NULL;
    return self;
}

void ndestroy(Node *self) {
    free(self->content);
    free(self->next);
    free(self);
}

Node *nget_next(Node *self) {
    return self->next;
}

void nset_next(Node *self, void *next) {
    self->next = next;
}

void *nget_content(Node *self) {
    return self->content;
}

void nset_content(Node *self, void *content) {
    self->content = content;
}
