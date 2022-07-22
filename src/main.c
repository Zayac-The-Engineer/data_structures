#include <LinkedList.h>
#include <Stack.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    LinkedList *ll = llcreate();
    Stack *st = stcreate();

    int *llnums = (int *)malloc(10 * sizeof (int));
    int *stnums = (int *)malloc(10 * sizeof (int));

    for (int i = 0; i < 10; i++) {
        llnums[i] = i;
        stnums[i] = i;
        printf("first loop: %i\n", i);
        llpush(ll, (void *)&llnums[i]);
        stpush(st, (void *)&stnums[i]);
    }

    printf("index 5: %i\n", *(int *)llget(ll, 5));

    for (int i = 0; i < 10; i++) {
        printf("second loop linkedlist: %i\n", *(int *)llpop(ll));
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("second loop stack     : %i\n", *(int *)stpop(st));
    }
    printf("\n");

    free(llnums);
    free(stnums);
    return EXIT_SUCCESS;
}
