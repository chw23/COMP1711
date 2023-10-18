# include <stdio.h>

/*
// question 5
int main () {
    int opt;

    printf("Choose your option from 1 to 5: ");
    scanf("%d", &opt);

    switch (opt) {
        case (1):
            printf("Option 1 is chosen.\n");
            break;
        case (2):
            printf("Option 2 is chosen.\n");
            break;
        case (3):
            printf("Option 3 is chosen.\n");
            break;
        case (4):
            printf("Option 4 is chosen.\n");
            break;
        case (5):
            printf("Option 5 is chosen.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}
*/

int main () {
    int num;

        while (num != -1) {
        printf("Please enter a number: ");
        scanf("%d\n", &num);
        
        if (num >= 0 && num <= 100) {
            printf("Wrong!\n");
            continue;
        }
        else if (num > 100) {
            printf("Too large!\n");
            continue;
        }
        else if (num <= -2) {
            printf("Too small!\n");
            continue;
        }
        }
        
    return 0;
}