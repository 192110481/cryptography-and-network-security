#include <stdio.h>
#include <string.h>

void monoalphabeticCipher(char* plainText, char* key) {
   char cipher;
   while(*plainText) {
      if(*plainText >= 'a' && *plainText <= 'z') {
         cipher = key[*plainText - 'a'];
      } else if(*plainText >= 'A' && *plainText <= 'Z') {
         cipher = key[*plainText - 'A'];
      } else {
         cipher = *plainText;
      }
      printf("%c", cipher);
      plainText++;
   }
}

int main() {
   char text[100];
   char key[27];
   printf("Enter the plain text: ");
   fgets(text, sizeof(text), stdin);
   printf("Enter the substitution key (26 unique letters): ");
   fgets(key, sizeof(key), stdin);
   printf("Ciphered text: ");
   monoalphabeticCipher(text, key);
   return 0;
}

