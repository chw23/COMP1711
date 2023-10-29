#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
    


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

// Complete the main function
int main() {
    int buffer_size = 100;
    int buffer2_size = 30;
    char buffer[buffer_size];
    char buffer2[buffer2_size];
    int i;
    int x = 0;

    FILE *data;
    data = fopen("FitnessData_2023.csv", "r");
    if (data == NULL) {
        perror("");
        return 1;
    }
    
    while (fgets(buffer, buffer_size, data) != NULL)
    {
        x = x + 1;
    }

    printf("Number of records in file: %d\n", x);

    for (i = 1; i <= 3; i++) {
        fgets(buffer2, buffer2_size, data);
        printf("%s",buffer2);
    }

    fclose(data);

    return 0;

}
