// AKTU First Year - File handling: write and read a file
#include <stdio.h>
int main() {
    FILE *fp;
    char text[200];
    fp = fopen("student.txt", "w");
    if (fp == NULL) { printf("Cannot open file\n"); return 1; }
    printf("Enter a line to write to file: ");
    fgets(text, sizeof(text), stdin);
    fputs(text, fp);
    fclose(fp);
    fp = fopen("student.txt", "r");
    if (fp == NULL) { printf("Cannot open file\n"); return 1; }
    printf("File content:\n");
    while (fgets(text, sizeof(text), fp) != NULL) printf("%s", text);
    fclose(fp);
    return 0;
}
