#include <stdio.h>

void convertToLower(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; 
        }
        i++;
    }
}

int main() {
    char str[100];
    printf("Enter an lowecase string: ");
    fgets(str, sizeof(str), stdin);
    convertToLower(str);
    printf("String in uppercase: %s\n", str);
return 0;
}

