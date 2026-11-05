// AKTU First Year - Loops: palindrome number
#include <stdio.h>
int main() {
    int n, rev = 0, rem, original;
    printf("Enter a number: ");
    scanf("%d", &n);
    original = n;
    while (n > 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    printf("%d is %s\n", original, (original == rev) ? "a palindrome" : "not a palindrome");
    return 0;
}
