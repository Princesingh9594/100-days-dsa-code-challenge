#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int left = 0, right;

    // Input
    scanf("%s", s);

    right = strlen(s) - 1;

    // Two-pointer comparison
    while(left < right) {
        if(s[left] != s[right]) {
            printf("NO");
            return 0;
        }
        left++;
        right--;
    }

    printf("YES");

    return 0;
}
