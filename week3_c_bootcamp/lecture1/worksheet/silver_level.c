# include <stdio.h>

int main () {
    int mark;

    printf("Please enter your mark: ");
    scanf("%d", &mark);

    if (mark >= 0 && mark <= 100) {
        
        if (mark >= 70) {
            printf("It is a distinction.\n");
        }
        else if (mark > 50) {
        printf("It is a pass.\n");
        }
        else {
            printf("It is a fail.\n");
            }
    }
    else {
        printf("Invalid value.\n");
    }
    
return 0;
}