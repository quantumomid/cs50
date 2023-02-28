#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("Chose a first number: \n");
    int y = get_int("Chose a second number: \n");

    // Notice how the placeholder uses letter '%i' to indicate its an Integer
    printf("The sum of these two numbers is: %i\n", x + y);
}