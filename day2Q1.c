#include <stdio.h>
int main() {
    int n, pos, i;
    printf("Enter the size of array");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position to delete");
    scanf("%d", &pos);
    if (pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("updated array:");
    for (i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
