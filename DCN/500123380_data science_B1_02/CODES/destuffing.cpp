#include <stdio.h>
#include <string.h>

void bitDestuffing(char *stuffedData, char *destuffedData) {
    int count = 0;
    int j = 0;

    for (int i = 0; i < strlen(stuffedData); i++) {
        destuffedData[j++] = stuffedData[i];

        if (stuffedData[i] == '1') {
            count++;
        } else {
            count = 0;
        }

        
        if (count == 5) {
            i++; 
            count = 0;
        }
    }
    destuffedData[j] = '\0'; 
}

int main() {
    char stuffedData[] = "11001111111100"; 
    char destuffedData[100]; 

    bitDestuffing(stuffedData, destuffedData);

    printf("Stuffed Data: %s\n", stuffedData);
    printf("Destuffed Data: %s\n", destuffedData);

    return 0;
}
