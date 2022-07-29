#include <stdio.h>
#include <stdlib.h>
#include <Stack.h>

int main() {
    Stack *st = stcreate();
    int *stnums = malloc(10 * sizeof (int));

    for (int i = 0; i < 10; i++) {
        stnums[i] = i;
        stpush(st, &stnums[i]);
    }

    for (int i = 0; i < 10; i++)
        printf("stack[%i]: %i\n", i, *(int *)stpop(st));

    stdestroy(st);
    free(stnums);

    return EXIT_SUCCESS;
}
