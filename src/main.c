#include <stdio.h>
#include <stdlib.h>

#include <LinkedList.h>
#include <Stack.h>
#include <Deque.h>

int main() {
    LinkedList *ll = llcreate();
    Stack *st = stcreate();
    Deque *dq = dqcreate();

    #define HEAP_ALLOC(type, x) (type *)malloc(x * sizeof (type))
    int *llnums = HEAP_ALLOC(int, 10);
    int *stnums = HEAP_ALLOC(int, 10);
    int *dqnums = HEAP_ALLOC(int, 10);
    #undef HEAP_ALLOC

    for (int i = 0; i < 10; i++) {
        llnums[i] = i;
        stnums[i] = i;
        dqnums[i] = i;

        printf("first loop            : %i\n", i);

        llpush(ll, (void *)&llnums[i]);
        stpush(st, (void *)&stnums[i]);
        dqpush_back(dq, (void *)&dqnums[i]);
    }

    printf("\nindex 5               : %i\n\n", *(int *)llget(ll, 5));

    for (int i = 0; i < 10; i++)
        printf("second loop linkedlist: %i\n", *(int *)llpop(ll));
    printf("\n");

    for (int i = 0; i < 10; i++)
        printf("second loop stack     : %i\n", *(int *)stpop(st));
    printf("\n");

    for (int i = 0; i < 10; i++)
        printf("pop back deque        : %i\n", *(int *)dqpop_back(dq));

    for (int i = 0; i < 10; i++)
        dqpush_front(dq, (void *)&dqnums[i]);
    printf("\n");

    for (int i = 0; i < 10; i++)
        printf("pop front deque       : %i\n", *(int *)dqpop_front(dq));

    lldestroy(ll);
    stdestroy(st);
    dqdestroy(dq);
    free(llnums);
    free(stnums);
    return EXIT_SUCCESS;
}
