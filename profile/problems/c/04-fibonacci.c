// AKTU First Year - Loops: Fibonacci series
#include <stdio.h>
int main() {
    int n, i, t1 = 0, t2 = 1, next;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("%d ", t1);
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
    printf("\n");
    return 0;
}
