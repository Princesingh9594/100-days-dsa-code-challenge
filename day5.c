#include <stdio.h>

int main() {
    int p, q, i, j, k;

    // Input size of first log
    scanf("%d", &p);
    int log1[p];

    // Input elements of first log
    for(i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Input size of second log
    scanf("%d", &q);
    int log2[q];

    // Input elements of second log
    for(i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int merged[p + q];

    i = 0; // pointer for log1
    j = 0; // pointer for log2
    k = 0; // pointer for merged array

    // Merge both logs
    while(i < p && j < q) {
        if(log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }

    // Copy remaining elements of log1
    while(i < p) {
        merged[k++] = log1[i++];
    }

    // Copy remaining elements of log2
    while(j < q) {
        merged[k++] = log2[j++];
    }

    // Print merged log
    for(i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
