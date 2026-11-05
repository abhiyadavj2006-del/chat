// AKTU First Year - Structures: student record
#include <stdio.h>
struct Student {
    int roll;
    char name[50];
    float marks;
};
int main() {
    struct Student s;
    printf("Enter roll, name and marks: ");
    scanf("%d %49s %f", &s.roll, s.name, &s.marks);
    printf("Roll: %d, Name: %s, Marks: %.2f\n", s.roll, s.name, s.marks);
    return 0;
}
