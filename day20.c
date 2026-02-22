#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, count = 0;

    // Since prefix sum can be negative, using larger array
    int size = 20001;
    int *freq = (int *)calloc(size, sizeof(int));

    // Offset to handle negative sums
    int offset = 10000;

    freq[offset] = 1;  // sum = 0 initially

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(freq[sum + offset] > 0) {
            count += freq[sum + offset];
        }

        freq[sum + offset]++;
    }

    printf("%d", count);

    free(freq);
    return 0;
}
