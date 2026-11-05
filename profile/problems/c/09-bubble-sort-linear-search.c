// AKTU First Year - Arrays: bubble sort and linear search
#include <stdio.h>
int main() {
    int n, i, j, temp, key, found = -1, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) { temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp; }
    printf("Sorted: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) if (arr[i] == key) { found = i; break; }
    if (found != -1) printf("Found at index %d\n", found);
    else printf("Not found\n");
    return 0;
}
