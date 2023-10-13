#include <stdio.h>

int main () {

    int N = 10;
    int array[N];
    int i;

    for (i = 0; i < N; i += 10000000) {
        array[i] = 10 * i + i;
    }

    for (i = 0; i < N; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }


    return 0;
}