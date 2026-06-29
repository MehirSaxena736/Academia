#include <stdio.h>

void convertToLower(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; 
        }
        i++;
    }
}

int main() {
    char str[100];
    printf("Enter an uppercase string: ");
    fgets(str, sizeof(str), stdin);
    convertToLower(str);
    printf("String in lowercase: %s\n", str);
return 0;
}

