#include <stdio.h>

void reverse_string(char *str) {
    int start = 0;
    int end = 0;
    char temp;

    // Find the length of the string
    while (str[end] != '\0') {
        end++;
    }
    end--; // Point to the last character

    // Swap characters from both ends
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char str[] = "Data Structures";

    reverse_string(str);

    printf("%s\n", str);

    return 0;
}
