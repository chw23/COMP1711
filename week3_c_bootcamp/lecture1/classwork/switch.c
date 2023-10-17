# include <stdio.h>

int main () {

    int label = -5;
    switch (label) {
        case 0:
            printf("0 was selected.\n");
        case 1:
            printf("1 was selected.\n");
        case 2:
            printf("2 was selected.\n");
        default:
            printf("Invalid.\n");

    }
    return 0;
}