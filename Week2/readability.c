#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int countSent(string str);
int countWords(string str);
int countLetters(string str);

int main(void) {
    
    // Get text from user
    string text = get_string("Text: ");
    
    // Calculate reading level
    float L = countLetters(text) * 100 / countWords(text);
    float S = countSent(text) * 100 / countWords(text);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    
    // Return reading level
    if(index < 1) {
        printf("Before Grade 1\n");
    } else if (index > 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", grade);
    }
}

int countSent(string str) {
    int i = 0;
    int sent = 0;

    while(str[i] != '\0') {
        // Check for end of sentence characters
        if(str[i] == '.' || str[i] == '!' || str[i] == '?') {
            sent++;
        }
        i++;
    }
    return sent;
}

int countWords(string str) {
    int j = 0;
    int wrd = 1;
    
    while(str[j] != '\0') {
        //Check for word breaks
        if(str[j] == ' ' || str[j] == '\n' || str[j] == '\t') {
            wrd++;
        }
        j++;
    }
    return wrd;
}

int countLetters(string str) {
    int let = 0;
    for(int k = 0; k < strlen(str); k++) {
        if(isalpha(str[k])) {
            let++;
        }
    }
    return let;
}