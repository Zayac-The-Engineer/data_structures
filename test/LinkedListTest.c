#include <stdio.h>
#include <stdlib.h>
#include <LinkedList.h>

int main() {
    LinkedList *ll = llcreate();
    int *llnums = (int *)malloc(10 * sizeof (int));

    for (int i = 0; i < 10; i++) {
        llnums[i] = i;
        llpush(ll, (void *)&llnums[i]);
    }

    for (int i = 0; i < 10; i++)
        printf("linkedlist[%i]: %i\n", i, *(int *)llpop(ll));

    lldestroy(ll);
    free(llnums);

    return EXIT_SUCCESS;
}
