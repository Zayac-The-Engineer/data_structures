#ifndef PAIR_H_
#define PAIR_H_

#include <stdlib.h>

typedef struct Pair Pair;

Pair *pcreate();
void pdestroy(Pair *self);

void *pget_key(Pair *self);
void pset_key(Pair *self, void *key);

void *pget_value(Pair *self);
void pset_value(Pair *self, void *value);

#endif // PAIR_H_
