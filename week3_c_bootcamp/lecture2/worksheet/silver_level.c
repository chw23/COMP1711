#include <stdio.h>
int length_of_string(char* p) {
    int count = 0;

    while (*p != '\0') {
        count++;
        p++;
    }

    return count;
}
int main() {
    char str[100];
    int length;

    printf("Enter any string : ");
    fgets(str);
    length = length_of_string(str);

    printf("The length of the given string : %d", length);

    return 0;
}

/*
int str_len (char *s) {
    int count = 0;

    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

int main () {
    char myString;
    int length;

    printf("Please input a string: ");
    scanf("%s", &myString);
    length = str_len(myString);

    printf("The length of the string: %d", length);

}
*/