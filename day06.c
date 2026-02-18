#include <stdio.h>

int main() {
    int n, i;

    // Input size
    scanf("%d", &n);

    if(n <= 0) {
        return 0;
    }

    int arr[n];

    // Input elements (sorted)
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Index for unique elements
    int index = 0;

    // Traverse array
    for(i = 1; i < n; i++) {
        if(arr[i] != arr[index]) {
            index++;
            arr[index] = arr[i];
        }
    }

    // Print unique elements
    for(i = 0; i <= index; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
