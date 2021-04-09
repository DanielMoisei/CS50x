#include <stdio.h>
#include <cs50.h>

int main(void) {
    int n;
    // Ask user for height input
    do {
        n = get_int("Height: ");
    } while(n < 1 || n > 8);

    // Build stairs
    for(int i = 0; i < n; i++) {
        // Add spaces
        for(int j = n - i; j > 1; j--) {
            printf(" ");
        }
        // Add first hash
        printf("#");
        // Finish hash row
        for(int k = 0; k < i; k++) {
            printf("#");
        }
        // Start new line
        printf("\n");
    }
}