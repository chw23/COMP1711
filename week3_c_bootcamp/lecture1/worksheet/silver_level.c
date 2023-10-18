# include <stdio.h>

/*
// question 3
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
*/

// question 4
int main () {
    int temp = 0;


    printf("Please enter the current temperature: ");
    scanf("%d", &temp);

    if (temp <= 40 && temp >= -10) {
        printf("Temperature is within the range.\n");
    }
    else {
        printf("Temperature is out of the range.\n");
    }
    return 0;
}