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
            //mostly ok but need to work on start_index
            //how to avoid clearing the start_index of the real longest period 
            counter = 0;
            int acc = 0;
            int start_index = 0;
            int longest_period = 0;

            while (fgets(buffer, buffer_size, input)) {
                tokeniseRecord(buffer, ",", DATA[counter].date, DATA[counter].time, DATA[counter].steps);

                if (atoi(DATA[counter].steps) >= 500) {
                    acc++;
                    if (atoi(DATA[counter - 1].steps) < 500) {
                        if 
                        start_index = counter;
                    }
                    
                }
                else {
                    if (acc <= longest_period) {
                        acc = 0;
                    }
                    else {
                        longest_period = acc;
                        acc = 0;
                    }
                }
                counter++;
            }
        /*counter = 0;
            int range = 0;
            int max_range = 0;
            int previous = 0;
            char Start_D[20];
            char Start_T[6];
            char End_D[20];
            char End_T[6];
            
            while (fgets(buffer, buffer_size, input)) {
                tokeniseRecord(buffer, ",", DATA[counter].date, DATA[counter].time, DATA[counter].steps);
                intsteps = atoi(DATA[counter].steps);
                if (intsteps > 500) {
                    if (previous <= 500) {
                        range = 0;
                        strcpy(Start_D, DATA[counter].date);
                        strcpy(Start_T, DATA[counter].time);
                    }
                    range++;
                }
                else {
                    if (range > max_range) {
                        max_range = range;
                        strcpy(End_D, DATA[counter - 1].date);
                        strcpy(End_T, DATA[counter - 1].time);
                    }
                    
                }
                counter++;
            }

            printf("Longest period start: %s %s\n", Start_D, Start_T);
            printf("Longest period end: %s %s\n", End_D, End_T);*/
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










