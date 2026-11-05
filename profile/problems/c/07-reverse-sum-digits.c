// AKTU First Year - Loops: reverse number and sum of digits
#include <stdio.h>
int main() {
    int n, rev = 0, sum = 0, rem;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n > 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        sum += rem;
        n /= 10;
    }
    printf("Reversed = %d, Sum of digits = %d\n", rev, sum);
    return 0;
}
