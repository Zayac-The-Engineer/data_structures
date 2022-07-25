#include <stdio.h>
#include <stdlib.h>
#include <Deque.h>

int main() {
    Deque *dq = dqcreate();
    int *dqnums = (int *)malloc(10 * sizeof (int));

    for (int i = 0; i < 10; i++) {
        dqnums[i] = i;
        dqpush_back(dq, (void *)&dqnums[i]);
    }
    for (int i = 0; i < 10; i++)
        printf("pop back deque[%i]: %i\n", i, *(int *)dqpop_back(dq));

    for (int i = 0; i < 10; i++)
        dqpush_front(dq, (void *)&dqnums[i]);

    for (int i = 0; i < 10; i++)
        printf("pop front deque[%i]: %i\n", i, *(int *)dqpop_front(dq));

    dqdestroy(dq);
    free(dqnums);

    return EXIT_SUCCESS;
}
