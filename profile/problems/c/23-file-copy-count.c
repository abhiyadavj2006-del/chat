// Advanced C - File handling: copy a file and count lines, words, characters
#include <stdio.h>
#include <ctype.h>
int main() {
    FILE *src, *dst;
    char ch;
    int lines = 0, words = 0, chars = 0, inWord = 0;
    src = fopen("input.txt", "r");
    if (src == NULL) { printf("input.txt not found. Create it first.\n"); return 1; }
    dst = fopen("output.txt", "w");
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
        chars++;
        if (ch == '\n') lines++;
        if (isspace((unsigned char)ch)) inWord = 0;
        else if (!inWord) { inWord = 1; words++; }
    }
    fclose(src);
    fclose(dst);
    printf("Copied to output.txt. Lines = %d, Words = %d, Characters = %d\n", lines, words, chars);
    return 0;
}
