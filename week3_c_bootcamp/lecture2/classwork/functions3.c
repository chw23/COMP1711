#include <stdio.h>
float sum (float a, float b)
{
    float answer;
    answer = a + b;
    return answer;
}

int main () 
{
    float y;
    printf("Choose a number: ");
    scanf("%f", &y);
    float z = sum(5, y); // calling our new function

    printf ("The sum of 5 and %.2f is %.2f\n", y, z);

    return 0;
}