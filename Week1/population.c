#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt for start size
    int n;
    do {
        n = get_int("Start size: ");
    } while (n < 9);
    //Prompt for end size
    int e;
    do {
        e = get_int("End size: ");
    } while (e < n);
    //Calculate number of years until we reach threshold
    int y = 0;
    do {
        n = n + n/3 - n/4;
        y++;
    } while (n < e);
    //Print number of years
    printf("Years: %i\n", y);
}