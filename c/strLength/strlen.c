#include <stdio.h>

int my_strlen(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    char str[] = "Hello, Vansh we will be learning the fundamental of C today.";

    printf("Length of the string: %d\n", my_strlen(str));

    return 0;
}
