#include <stdio.h>

int main() {
    char str[100];
    int i = 0;
    int j = 0;

    printf("Enter a string: ");

    scanf(" %[^\n]", str);

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';

    printf("String without spaces: %s\n", str);

    return 0;
}
