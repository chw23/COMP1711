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
    FITNESS_DATA DATA[150];

    char inputbuffer[buffer_size];
    char buffer[buffer_size];

    char choice;
    char filename[buffer_size];
    int counter;
    int intsteps;

    while (1) {
    
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

            printf("Input filename: ");
            fgets(buffer, buffer_size, stdin);
            sscanf(buffer, "%s", filename);
            
            FILE *input;
            input = fopen(filename, "r");

            if (!input) {
                printf("Error: Could not find or open the file.\n");
                return(1);
            }
            else {
                printf("File successfully loaded.\n");
            }
            break;

        case 'B':
        case 'b':
            rewind(input);  //to read input from the beginning 
            counter = 0;
            while (fgets(buffer, buffer_size, input) != NULL) {
                counter += 1;
            }
            printf("Total records: %d\n", counter);
            break;

        case 'C':
        case 'c':
            rewind(input);
            counter = 0;
            int minimum = 10000;
            char min_date[20];
            char min_time[10];
            while (fgets(buffer, buffer_size, input)) {
                tokeniseRecord(buffer, ",", DATA[counter].date, DATA[counter].time, DATA[counter].steps);
                intsteps = atoi(DATA[counter].steps);
                if (intsteps < minimum) {
                    minimum = intsteps;
                    strcpy(min_date, DATA[counter].date);
                    strcpy(min_time, DATA[counter].time);
                }
                counter++;
            }
            printf("Fewest steps: %s %s\n", min_date, min_time);
            break;
        
        case 'D':
        case 'd':
            rewind(input);
            counter = 0;
            int maximum = 0;
            char max_date[20];
            char max_time[10];
            while (fgets(buffer, buffer_size, input)) {
                tokeniseRecord(buffer, ",", DATA[counter].date, DATA[counter].time, DATA[counter].steps);
                intsteps = atoi(DATA[counter].steps);
                if (intsteps > maximum) {
                    maximum = intsteps;
                    strcpy(max_date, DATA[counter].date);
                    strcpy(max_time, DATA[counter].time);
                }
                counter++;
            }
            printf("Largest steps: %s %s\n", max_date, max_time);
            break;

        case 'E':
        case 'e':
            rewind(input);
            counter = 0;
            float mean = 0;
            while (fgets(buffer, buffer_size, input)) {
                tokeniseRecord(buffer, ",", DATA[counter].date, DATA[counter].time, DATA[counter].steps);
                intsteps = atoi(DATA[counter].steps);
                mean = (mean + intsteps);
                counter++;
            }
            mean = (mean/counter);
            int roundmean = round(mean);
            printf("Mean step count: %d\n", roundmean);
            break;

        case 'F':
        case 'f':
            counter = 0;
            int acc = 0;
            int start_index = 0;
            int longest_period = 0;
            int current_start_index = 0; // saving the starting index of current period

            while (fgets(buffer, buffer_size, input)) {
                tokeniseRecord(buffer, ",", DATA[counter].date, DATA[counter].time, DATA[counter].steps);

                if (atoi(DATA[counter].steps) > 500) {
                    acc++;  
                }
                else {
                    if (acc > longest_period) {
                        longest_period = acc;
                        start_index = current_start_index;
                    }
                    acc = 0;
                    current_start_index = counter + 1; // to update index of the next row
                }
                counter++;
            }

            if (acc > longest_period) {
                longest_period = acc;
                start_index = current_start_index;
            }
            printf("Longest period start: %s %s\n", DATA[start_index].date, DATA[start_index].time);
            printf("Longest period end: %s %s\n", DATA[start_index + longest_period - 1].date, DATA[start_index + longest_period - 1].time);
            return 0;                                                                                                                                  
            break;

        case 'Q':
        case 'q':
            fclose(input);
            return 0;
            break;
        
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
        
    }
}










