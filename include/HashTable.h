#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "Pair.h"
#include <stdint.h>

typedef struct HashTable HashTable;

HashTable *htcreate();
void htdestroy(HashTable* self);
void htput(HashTable *self, uint8_t *key, void *value);
void *htget(HashTable *self, uint8_t* key);

#endif // HASHTABLE_H_
