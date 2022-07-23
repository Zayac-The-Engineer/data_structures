#ifndef NODE_H_
#define NODE_H_

#include <stdlib.h>

typedef struct Node Node;

Node *ncreate();
void ndestroy(Node *self);

void *nget_content(Node *self);
void nset_content(Node *self, void *content);

Node *nget_next(Node *self);
void nset_next(Node *self, Node *next);

#endif // NODE_H_
