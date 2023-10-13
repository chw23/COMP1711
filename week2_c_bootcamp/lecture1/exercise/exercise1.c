#include <stdio.h>

int main () {

    float height;
    float base;

    printf("Enter the height= ");
    scanf("%f", &height);
    printf("Enter the base= ");
    scanf("%f", &base);

    float area = height*base ;

    printf("The area is: %f\n", area);

    return 0;
}