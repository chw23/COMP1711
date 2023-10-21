# include <stdio.h>
# include <math.h>

/*
// question 1
float circleArea (float r) {
    float area;
    area = M_PI * r * r;
    return area;
}

int main () {
    float radius;

    printf("Enter a value for radius: ");
    scanf("%f", &radius);

    float area = circleArea(radius);

    printf("The area of the circle is %.2f.\n", area);

    return 0;
}
*/

// question 2

float SphereVolume (float r) {
    float volume;
    volume = ((4.0 / 3.0) * 3.14 * (r * r * r));
    return volume;
}

int main () {
    float radius;
    float result;

    printf("Please enter the radius: ");
    scanf("%f", &radius);
    result = SphereVolume(radius);

    printf("The volume of the sphere is %.2f.\n", result);

    return 0;
}