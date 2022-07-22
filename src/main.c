#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    LinkedList *ll = llcreate();

    int *nums = (int *)malloc(10 * sizeof (int));

    for (int i = 0; i < 10; i++) {
        nums[i] = i;
        printf("first loop: %i\n", i);
        llpush(ll, (void *)&nums[i]);
    }

    printf("index 5: %i\n", *(int *)llget(ll, 5));

    for (int i = 0; i < 10; i++) {
        printf("second loop: %i\n", *(int *)llpop(ll));
    }

    return EXIT_SUCCESS;
}
