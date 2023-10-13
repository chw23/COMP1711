#include <stdio.h>
int main () {
    int a = 5, b = 2;
    printf("%d", a/b);

    int temp = a;
    a = b;
    b = temp;

    printf("a = %d, b = %d\n", a, b);
    return 0;
}