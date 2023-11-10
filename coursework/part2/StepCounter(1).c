#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Complete the main function
int main() {
    int buffer_size = 100;
    int buffer2_size = 30;
    char buffer[buffer_size];
    char buffer2[buffer2_size];
    int stepsint;
    int i;
    int x = 0;
    

    FILE *data;
    data = fopen("FitnessData_2023.csv", "r");
    if (data == NULL) {
        perror("");
        return 1;
    }
    
    while (fgets(buffer, buffer_size, data) != NULL) {
        x = x + 1;
    }

    printf("Number of records in file: %d\n", x);

    FILE *data2;
    data2 = fopen("FitnessData_2023.csv", "r");
    if (data2 == NULL) {
        perror("");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        char date[11];
        char time[6];
        char steps[10];
        fgets(buffer2, buffer2_size, data2);
        tokeniseRecord(buffer2, ",", date, time, steps);
        printf("%s/%s/", date, time);
        stepsint = atoi(steps);
        printf("%d\n", stepsint);
        
    }

    fclose(data);

    return 0;

}
