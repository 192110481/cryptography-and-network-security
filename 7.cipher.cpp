#include <stdio.h>
#include <string.h>

#define SIZE 26

// Function to decrypt the message
void decrypt(char* cipherText, char* key) {
    char plainText[strlen(cipherText) + 1];
    for (int i = 0; cipherText[i] != '\0'; i++) {
        if (cipherText[i] != ' ') {
            plainText[i] = key[cipherText[i] - 'A'];
        } else {
            plainText[i] = ' ';
        }
    }
    plainText[strlen(cipherText)] = '\0';
    printf("Decrypted Message: %s\n", plainText);
}

int main() {
    char cipherText[100];
    char key[SIZE + 1];

    printf("Enter ciphertext: ");
    fgets(cipherText, sizeof(cipherText), stdin);
    cipherText[strcspn(cipherText, "\n")] = 0;  // Remove trailing newline

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;  // Remove trailing newline

    decrypt(cipherText, key);

    return 0;
}

