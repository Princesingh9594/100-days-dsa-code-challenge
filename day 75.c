#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    int hash[100000] = {0};
    int visited[100000] = {0};

    int offset = 50000;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            max_len = i + 1;

        if (visited[sum + offset]) {
            int prev_index = hash[sum + offset];
            if (i - prev_index > max_len)
                max_len = i - prev_index;
        } else {
            hash[sum + offset] = i;
            visited[sum + offset] = 1;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLen(arr, n));

    return 0;
}
