#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    int n;
    struct student new_student = {};       // = {.name = "How Areyou", .student_id = "27655657449", 99};
    //printf("Insert data [name, id, mark]\n");
    //scanf("%s", &new_student.name);
    //scanf("%s", &new_student.student_id);
    //scanf("%d", &new_student.mark);
    strcpy(new_student.name, "Name Surename");
    strcpy(new_student.student_id, "111111");
    char mark_string = "35";
    new_student.mark = atoi(mark_string);

    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}