#include "Pair.h"

struct Pair {
    void *key;
    void *value;
};

Pair *pcreate() {
    return (Pair *)calloc(1, sizeof (Pair));
}

void pdestroy(Pair *self) {
    free(self);
}

void *pget_key(Pair *self) {
    return self->key;
}

void pset_key(Pair *self, void *key) {
    self->key = key;
}

void *pget_value(Pair *self) {
    return self->value;
}

void pset_value(Pair *self, void *value) {
    self->value = value;
}
