#include <stdio.h>
float div (float, float);

int main () 
{
    float y = 2.11;
    float z = div(y, 5.11); // calling our new function

    printf ("The sum of 5.11 and %.2f is %2.2f\n", y, z);
}

float div (float a, float b)
{
    int answer;
    answer = a / b;
    return answer;
}
