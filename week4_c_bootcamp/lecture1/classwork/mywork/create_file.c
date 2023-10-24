#include <stdio.h>
#include "utils.h"

int main () {
    char filename[] = "data.txt";
    FILE *file = open_file(filename, "r");
   
    int buffer_size = 100;
    char buffer[buffer_size];

    while (fgets(buffer, buffer_size, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);

    return 0;
}