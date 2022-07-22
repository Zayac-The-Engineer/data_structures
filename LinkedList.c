#include "LinkedList.h"
#include "Node.h"

struct LinkedList {
    Node *head;
};

LinkedList *llcreate() {
    LinkedList *self = (LinkedList *)malloc(sizeof (LinkedList));
    self->head = NULL;
    return self;
}

void lldestroy(LinkedList *self) {
    Node* n = self->head;
    while (n != NULL) {
        Node* next = nget_next(n);
        ndestroy(n);
        n = next;
    }
    free(self);
}

void llpush(LinkedList *self, void *content) {
    Node *n;
    for (n = self->head; n != NULL; n = nget_next(n));

    nset_next(n, (Node *)malloc(sizeof (Node *)));
    nset_content(nget_next(n), content);
}

Node *llpop(LinkedList *self) {
    void *content = nget_content(self->head);
    ndestroy(self->head);
    self->head = nget_next(self->head);
    return content;
}

Node *llget_head(LinkedList *self) {
    return self->head;
}
