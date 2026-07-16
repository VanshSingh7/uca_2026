#include <stdio.h>

int find_substring(const char *haystack, const char *needle)
{
    int i, j;

    // '\0' represent last char of string
    if (needle[0] == '\0')
        return 0;

    for (i = 0; haystack[i] != '\0'; i++) {
        j = 0;

        // Check characters of needle
        while (haystack[i + j] != '\0' &&
               needle[j] != '\0' &&
               haystack[i + j] == needle[j])
       	{
            j++;
        }

        // Complete needle matched
        if (needle[j] == '\0')
            return i;
    }

    return -1;
}

int main() {
    const char haystack[] = "Embedded Systems";
    const char needle[] = "bed";

    int result = find_substring(haystack, needle);

    printf("%d\n", result);

    return 0;
}
