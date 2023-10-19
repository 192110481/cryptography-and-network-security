#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

// Function to calculate multiplicative inverse of a
int multiplicativeInverse(int a) {
    a = a % SIZE;
    for (int x = 1; x < SIZE; x++)
        if ((a * x) % SIZE == 1)
            return x;
    return -1;
}

// Function to decrypt the message
void decrypt(char* cipherText, int a, int b) {
    char plainText[strlen(cipherText) + 1];
    int a_inv = multiplicativeInverse(a);
    if (a_inv == -1) {
        printf("Multiplicative inverse of key(A) doesn't exist");
        return;
    }
    for (int i = 0; cipherText[i] != '\0'; i++) {
        if (cipherText[i] != ' ') {
            plainText[i] = (char)(((a_inv * ((cipherText[i] + 'A' - b)) % SIZE)) + 'A');
        } else {
            plainText[i] = ' ';
        }
    }
    plainText[strlen(cipherText)] = '\0';
    printf("Decrypted Message: %s\n", plainText);
}

int main() {
    char cipherText[100];
    int a, b;

    printf("Enter ciphertext: ");
    fgets(cipherText, sizeof(cipherText), stdin);
    cipherText[strcspn(cipherText, "\n")] = 0;  // Remove trailing newline

    printf("Enter key A: ");
    scanf("%d", &a);

    printf("Enter key B: ");
    scanf("%d", &b);

    decrypt(cipherText, a, b);

    return 0;
}

