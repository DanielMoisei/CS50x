#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    // Check for multiple CL arguments
    if(argc != 2) {
        printf("Usage: ./caesar key\n");
    }
    
    // Convert the key to an integer
    int key = atoi(argv[1]);
    
    // Get plain text from user
    string plain = get_string("plaintext: ");
    
    // Encode the text and print it
    printf("ciphertext: ");
    for(int i = 0, n = strlen(plain); i < n; i++) {
        // Check if the char is a lowercase letter
        if islower(plain[i]) {
            printf("%c", (((plain[i] + key) - 97) % 26) + 97);
        // Check if the char is an uppercase letter
        } else if isupper(plain[i]) {
            printf("%c", (((plain[i] + key) - 65) % 26) + 65);
        // Print punctuation as it is
        } else {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
