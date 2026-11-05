// AKTU First Year - Strings: reverse and vowel count
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char str[200];
    int i, len, vowels = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    len = strlen(str);
    printf("Reversed: ");
    for (i = len - 1; i >= 0; i--) printf("%c", str[i]);
    printf("\n");
    for (i = 0; i < len; i++) {
        char ch = tolower((unsigned char)str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowels++;
    }
    printf("Vowel count = %d\n", vowels);
    return 0;
}
