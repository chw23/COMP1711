#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

#define buffer_size 150

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {
    FitnessData DATA[150];
    char buffer[buffer_size];
    char filename[buffer_size];
    int counter = 0;
    
    printf("Enter filename: ");
    fgets(buffer, buffer_size, stdin);
    sscanf(buffer, "%s", filename);

    FILE *input;
    input = fopen(filename, "r");

    if (!input) {
        printf("Error: invalid file.\n");
        return(1);
    }

    while (fgets(buffer, buffer_size, input) != NULL) {
        tokeniseRecord(buffer, ',', DATA[counter].date, DATA[counter].time, &DATA[counter].steps);
        if (DATA[counter].date[7] && DATA[counter].date[4] != 45) {
            printf("Error: invalid file.\n");
            return(1);
        }

        if (DATA[counter].time[2] != 58) {
            printf("Error: invalid file.\n");
            return(1);
        }

        char csteps[4];
        sprintf (csteps, "%d", DATA[counter].steps);
        printf("%s\n", csteps);
        if (csteps[0] <= 48  || csteps[0] > 57) {
            printf("Error: invalid file.\n");
            return(1);
        }
        counter++;
    }

    

    return 0;
}
