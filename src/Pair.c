#include "Pair.h"
#include <stdlib.h>

struct Pair {
    uint8_t *key;
    void *value;
    size_t key_size;
};

Pair *pcreate(void *key, uint8_t *value, size_t key_size) {
    Pair *self = calloc(1, sizeof (Pair));
    self->key = key;
    self->value = value;
    self->key_size = key_size;
    return self;
}

/* this thing may or may not leak memory
 * The value and key memory should be managed outside */
void pdestroy(Pair *self) {
    free(self);
}

uint8_t *pget_key(Pair *self) {
    return self->key;
}

/* void pset_key(Pair *self, void *key) { */
/*     self->key = key; */
/* } */

void *pget_value(Pair *self) {
    return self->value;
}

void pset_value(Pair *self, void *value) {
    self->value = value;
}
