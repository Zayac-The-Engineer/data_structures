#include "LinkedList.h"
#include "Node.h"

struct LinkedList {
    Node *head;
};

LinkedList *llcreate() {
    return (LinkedList *)calloc(1, sizeof (LinkedList));
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
    if (self->head == NULL) {
        self->head = ncreate();
        nset_content(self->head, content);
        return;
    }

    Node *n;
    for (n = self->head; nget_next(n) != NULL; n = nget_next(n));

    nset_next(n, (Node *)malloc(sizeof (Node *)));
    nset_content(nget_next(n), content);
}

void *llpop(LinkedList *self) {
    void *content = nget_content(self->head);
    Node *buf = nget_next(self->head);
    ndestroy(self->head);
    self->head = buf;
    return content;
}

void *llget(LinkedList *self, size_t idx) {
    Node *n;
    size_t i = 0;
    for (n = self->head; i++ < idx; n = nget_next(n))
        if (nget_next(n) == NULL)
            return NULL;
    return nget_content(n);
}
