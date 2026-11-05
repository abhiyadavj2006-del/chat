// Advanced C - Dynamic memory: array using malloc and free
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, sum = 0, *arr;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) { printf("Memory allocation failed\n"); return 1; }
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) { scanf("%d", &arr[i]); sum += arr[i]; }
    printf("Sum = %d, Average = %.2f\n", sum, (float)sum / n);
    free(arr);
    return 0;
}
