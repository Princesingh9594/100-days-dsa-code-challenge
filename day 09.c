#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int i, length;
    char temp;

    // Input
    scanf("%s", str);

    // Find length of string
    length = strlen(str);

    // Reverse the string using two-pointer approach
    for(i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    // Output
    printf("%s", str);

    return 0;
}
