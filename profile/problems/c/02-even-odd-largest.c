// AKTU First Year - Conditional branching: even/odd and largest of three
#include <stdio.h>
int main() {
    int a, b, c, largest;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("%d is %s\n", a, (a % 2 == 0) ? "even" : "odd");
    largest = a;
    if (b > largest) largest = b;
    if (c > largest) largest = c;
    printf("Largest = %d\n", largest);
    return 0;
}
