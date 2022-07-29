#include "HashTable.h"
#include "LinkedList.h"
#include "Node.h"
#include "Pair.h"
#include <stddef.h>
#include <stdint.h>

struct HashTable {
    LinkedList **buckets;
    size_t capacity;
    size_t key_size;
};

size_t hash_function(HashTable *self, uint8_t *key);

/* Compares same-size arrays */
uint8_t compare_data(uint8_t *a, uint8_t *b, size_t array_size);

#define INITIAL_CAPACITY 16
HashTable *htcreate(size_t key_size) {
    HashTable *self = calloc(1, sizeof (HashTable));
    self->buckets = calloc(INITIAL_CAPACITY, sizeof (LinkedList *));
    self->capacity = INITIAL_CAPACITY;

    for (size_t i = 0; i < INITIAL_CAPACITY; i++) {
        self->buckets[i] = llcreate();
    }
    return self;
}
#undef INITIAL_CAPACITY

void htdestroy(HashTable *self) {
    for (size_t i = 0; i < self->capacity; i++) {
        lldestroy(self->buckets[i]);
    }
    free(self->buckets);
    free(self);
}

/* for now it assumes you don't put in the same key */
void htput(HashTable *self, uint8_t *key, void *value) {
    Pair *entry = pcreate(key, value, self->key_size);
    llpush(self->buckets[hash_function(self, key)], entry);
}

void *htget(HashTable *self, uint8_t *key) {
    /* ll contains Nodes which contain Pairs */
    LinkedList *ll = self->buckets[hash_function(self, key)];

    for (Node *n = llget_head(ll); nget_next(n) != NULL; n = nget_next(n)) {
        if (compare_data(pget_key(nget_content(n)), key, self->key_size))
            return pget_value(nget_content(n));
    }
    return NULL;
}

size_t hash_function(HashTable *self, uint8_t *key) {
    int sum = 0x0;
    for (size_t i = 0; i < self->key_size; i++) {
        sum += key[i] * (i * 0x10);
    }
    return sum / self->capacity;
}

#define TRUE 1;
#define FALSE 0;
uint8_t compare_data(uint8_t *a, uint8_t *b, size_t array_size) {
    for (size_t i = 0; i < array_size; i++) {
        if (a[i] != b[i])
            return FALSE;
    }
    return TRUE;
}
#undef TRUE
#undef FALSE
