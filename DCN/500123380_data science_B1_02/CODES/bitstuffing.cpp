#include <stdio.h>
#include <string.h>

void bitStuffing(char *data, char *stuffedData) {
    int count = 0;
    int j = 0;

    for (int i = 0; i < strlen(data); i++) {
        stuffedData[j++] = data[i];

        if (data[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        
        if (count == 5) {
            stuffedData[j++] = '0';
            count = 0;
        }
    }
    stuffedData[j] = '\0'; 
}

int main() {
    char data[] = "110111111111110";
    char stuffedData[100]; 

    bitStuffing(data, stuffedData);

    printf("Original Data: %s\n", data);
    printf("Stuffed Data: %s\n", stuffedData);

    return 0;
}
