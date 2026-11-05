// AKTU First Year - Arrays: largest, smallest and average
#include <stdio.h>
int main() {
    int n, i, arr[100], largest, smallest, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    largest = smallest = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] > largest) largest = arr[i];
        if (arr[i] < smallest) smallest = arr[i];
        sum += arr[i];
    }
    printf("Largest = %d, Smallest = %d, Average = %.2f\n", largest, smallest, (float)sum / n);
    return 0;
}
