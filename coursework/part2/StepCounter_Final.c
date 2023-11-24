#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array

// Inspired by week7 material: code.c 
// Complete the main function
int main() {
    FITNESS_DATA DATA[100];

   char buffer[buffer_size];

   char choice;
   char filename[] = "FitnessData_2023.csv";
   int counter;
   int intsteps;
   
   while (1) {
    FILE *input;
    input = fopen(filename, "r");

    printf("Menu option:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the data and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Exit the program\n");
    printf("Enter choice: ");
    choice = getchar();

    while (getchar() != '\n');

    switch (choice) {
        case 'A':
        case 'a':
            if (!input) {
                printf("Error: Could not find or open the file.\n");
            }
            else {
                printf("Input filename: %s\n", filename);
                printf("File successfully loaded.\n");
            }
            break;

        case 'B':
        case 'b':
            counter = 0;
            while (fgets(buffer, buffer_size, input) != NULL) {
                counter += 1;
            }
            printf("Total number of records in the file: %d\n", counter);
            break;

        case 'C':
        case 'c':
            counter = 0;
            int minimum = 10000;
            char min_date;
            char min_time;
            while (fgets(buffer, buffer_size, input)) {
                tokeniseRecord(buffer, ",", DATA[counter].date, DATA[counter].time, DATA[counter].steps);
                intsteps = atoi(DATA[counter].steps);
                if (intsteps < minimum) {
                    minimum = intsteps;
                    //strcpy(DATA[counter].date, min_date);
                    //strcpy(DATA[counter].time, min_time);
                }
                counter++;
            }
            //printf("The date and time of the timeslot with the fewest steps: %s/%s\n", min_date, min_time);
            break;
        
        case 'D':
        case 'd':
            counter = 0;
            int maximum = 0;
            char max_date;
            char max_time;
            while (fgets(buffer, buffer_size, input)) {
                tokeniseRecord(buffer, ",", DATA[counter].date, DATA[counter].time, DATA[counter].steps);
                intsteps = atoi(DATA[counter].steps);
                if (intsteps > maximum) {
                    maximum = intsteps;
                    //max_date = DATA[counter].date;
                    //max_time = DATA[counter].time;
                }
                counter++;
            }
            //printf("The date and time of the timeslot with the largest number of steps: %d/%d\n", max_date, max_time);
            break;

        case 'E':
        case 'e':
            counter = 0;
            int mean = 0;
            while (fgets(buffer, buffer_size, input)) {
                tokeniseRecord(buffer, ",", DATA[counter].date, DATA[counter].time, DATA[counter].steps);
                intsteps = atoi(DATA[counter].steps);
                mean = (mean + intsteps);
                counter++;
            }
            mean = (mean/counter);
            printf("The mean step count of all the records is %d.\n", mean);
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









