#include <stdio.h>

void url_encode(char *str, int true_length) {
    char result[100];
    int i, j = 0;

    // resulting array with encoding
    for (i = 0; i < true_length; i++)
    {
        if (str[i] == ' ')
        {
            result[j++] = '%';
            result[j++] = '2';
            result[j++] = '0';
        }
        else
        {
            result[j++] = str[i];
        }
    }

    result[j] = '\0';

    // Copy result back to original string
    for (i = 0; i <= j; i++)
    {
        str[i] = result[i];
    }
}

int main()
{
    char str[50] = "Hello World   ";

    url_encode(str, 11);

    printf("%s\n", str);

    return 0;
}
