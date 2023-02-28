#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("Chose a first number: \n");
    int y = get_int("Chose a second number: \n");

    // type-casting for x and y so that treated as floats and decimals preserved throughout
    float z = (float)x / (float)y;

    // placeholder uses letter '%f' to indicate its FLOAT
    printf("The first divided by the second is: %f\n", z);
}