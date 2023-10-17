# include <stdio.h>
/*
// question 1
int main () {

    int num;

    printf("Please enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Number is negative.\n");
    }
    else if (num == 0) {
        printf("Number is zero.\n");
    }
    else {
        printf("Number is positive.\n");
    }
    return 0;
}
*/

// question 2
int main () {
    int num;

    printf("Please enter a number: ");
    scanf("%d", &num);

    if (num % 4 == 0) {
        if (num % 5 == 0) {
            printf("%d can be divided by 4 and 5.\n", num);
        }
        else {
            printf("%d can be divided by 4.\n", num);
        }
    }
    else if (num % 5 == 0) {
        printf("%d can be divided by 5.\n", num);
    }
    else {
        printf("%d cannot be divided by 4 or 5.\n", num);
    }
    return 0;
}