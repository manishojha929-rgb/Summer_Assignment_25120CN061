#include <stdio.h>

int main() {
    char str[100];
    int i = 0;
    int words = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]", str);

    while (str[i] != '\0') {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0')) {
            words++;
        }
        i++;
    }

    printf("Total words: %d\n", words);

    return 0;
}
