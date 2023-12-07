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
    int i = 0;
    
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
        if (csteps[0] <= 48  || csteps[0] > 57) {
            printf("Error: invalid file.\n");
            return(1);
        }
        counter++;
    }

    // I based this on ideas I found here:
    // https://discuss.codechef.com/t/sorting-structure-in-c-using-qsort/49541/3
    // https://www.youtube.com/watch?v=rHoOWG6Ihs4&ab_channel=PortfolioCourses
    // Also the discussion with chatGPT on clarifying the functions and codes

    int compare (const void *ps1, const void *ps2) {
        const FitnessData *s1 = (const FitnessData *)ps1;
        const FitnessData *s2 = (const FitnessData *)ps2;
        int step1 = s1 -> steps;
        int step2 = s2 -> steps;
        return (step2 - step1);
    }

    size_t size = sizeof(DATA) / sizeof(DATA[0]);
    qsort(DATA, counter, sizeof(FitnessData), compare);

    strcat(filename, ".tsv");

    FILE *output;
    output = fopen(filename, "w+");
    for (i = 0; i < counter; i++) {
        fprintf(output, "%s\t%s\t%d\n", DATA[i].date, DATA[i].time, DATA[i].steps);
    }
    fclose(output);
    return 0;
}
