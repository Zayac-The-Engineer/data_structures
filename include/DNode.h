#ifndef DNODE_H_
#define DNODE_H_

#include <stdlib.h>

typedef struct DNode DNode;

DNode *dncreate();
void dndestroy(DNode *self);

void *dnget_content(DNode *self);
void dnset_content(DNode *self, void *content);

DNode *dnget_next(DNode *self);
void dnset_next(DNode *self, DNode *next);

DNode *dnget_prev(DNode *self);
void dnset_prev(DNode *self, DNode *prev);

#endif // DNODE_H_
