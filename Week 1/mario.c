#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declare variable without any assignment
    int n;

    // For validation => keep asking user if they respond with a non-integer response
    do
    {
        n = get_int("Choose a number? ");
    } while (n <= 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}