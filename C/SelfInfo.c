#include <stdio.h>

int main() {
    char name[20], class_name[10];
    char div[3];
    int rollno;

    printf("Enter Student name: ");
    scanf("%s", name);

    printf("Enter Roll number: ");
    scanf("%d", &rollno);

    printf("Enter class of student: ");
    scanf("%s", class_name);

    printf("Specify Division of student: ");
    scanf("%s", div);

    printf("\nName: %s\n", name);
    printf("Roll number: %d\n", rollno);
    printf("Class: %s\n", class_name);
    printf("Division: %s\n", div);

    return 0;
}