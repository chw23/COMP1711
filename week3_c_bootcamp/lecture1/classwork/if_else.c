# include <stdio.h>

int main () {
    int mark;

    printf("Please enter your mark: ");
    scanf("%d", &mark);

    if (mark >= 40 && mark <= 100) {
        if (mark >= 40) {
            printf("Passed.\n");
            }
        else if (mark 
            printf("Failed.\n");
            }
    }
    else {
        printf("Mark should be within 0 and 100.\n");
    }
    return 0;
}