#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }



// Inspired by week7 material: code.c 
// Complete the main function
int main() {
    FITNESS_DATA DATA[100];

   char buffer[buffer_size];

   char choice;
   int counter = 0;
   
   while (1) {
    FILE *input;
    input = fopen("FitnessData_2023.csv", "r");

    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the data and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Exit the program\n");

    choice = getchar();

    while (getchar() != '\n');

    switch (choice) {
        case 'A':
        case 'a':
            if (!input) {
                printf("Error: Could not find or open the file.\n");
            }
            else {
                printf("Input filename: \n");
                printf("File successfully loaded.\n");
            }

            break;

        case 'B':
        case 'b':
            counter = 0;
            while (fgets(buffer, buffer_size, input) != NULL) {
                counter = counter + 1;
            }
            printf("Total number of records in the file: %d\n", counter);
            break;

        case 'C':
        case 'c':
            counter = 0;
            int minimum = 10000;
            int intsteps;
            char min_date;
            char min_time;
            while (fgets(buffer, buffer_size, input)) {
                tokeniseRecord(buffer, ",", &DATA[counter].date, &DATA[counter].time, &DATA[counter].steps);
                intsteps = atoi(steps);
                if (steps < minimum) {
                    minimum = DATA[counter].steps;
                    min_date = DATA[counter].date;
                    min_time = DATA[counter].time;
                }
                counter++;
            }
            printf("The date and time of the timeslot with the fewest steps: %s/%s", min_date, min_time);
            break;

        case 'D':
        case 'd':
            return 0;
            break;

        case 'E':
        case 'e':
            return 0;
            break;

        case 'F':
        case 'f':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;
        
        default:
            printf("Invalid choice\n");
            break;
    }
   }


}









