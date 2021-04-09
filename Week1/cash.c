#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    float change;
    do {
        change = get_float("Change owed: ");
    } while (change < 0);

    int changeCents = round(change * 100);

    int quarters, dimes, nickels, cents, coins;

    quarters = changeCents / 25;
    changeCents = changeCents - quarters * 25;

    dimes = changeCents / 10;
    changeCents = changeCents - dimes * 10;

    nickels = changeCents/5;
    changeCents = changeCents - nickels * 5;

    cents = changeCents;

    coins = quarters + dimes + nickels + cents;

    printf("%i\n", coins);

}