// Advanced C - Structures: array of structures, find topper
#include <stdio.h>
struct Student {
    int roll;
    char name[50];
    float marks;
};
int main() {
    int n, i, topper = 0;
    struct Student students[100];
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Student %d - roll, name, marks: ", i + 1);
        scanf("%d %49s %f", &students[i].roll, students[i].name, &students[i].marks);
        if (students[i].marks > students[topper].marks) topper = i;
    }
    printf("Topper: %s (Roll %d) with %.2f marks\n", students[topper].name, students[topper].roll, students[topper].marks);
    return 0;
}
