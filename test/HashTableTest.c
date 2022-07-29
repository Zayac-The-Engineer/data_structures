#include <HashTable.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    HashTable *ht = htcreate(sizeof (char));

    uint8_t *keys = malloc(7 * sizeof (char));
    char **values = malloc(7 * sizeof (char *));
    values[0] = "one\0";
    values[1] = "two\0";
    values[2] = "three\0";
    values[3] = "four\0";
    values[4] = "five\0";
    values[5] = "six\0";
    values[6] = "seven\0";

    for (int i = 0; i < 7; i++) {
        keys[i] = i + 97;
        htput(ht, &keys[i], values[i]);
    }

    for (int i = 0; i < 7; i++) {
        printf("HashTable[%c]: %s\n", keys[i], (char *)htget(ht, &keys[i]));
    }

    htdestroy(ht);
    free(keys);

    return EXIT_SUCCESS;
}
