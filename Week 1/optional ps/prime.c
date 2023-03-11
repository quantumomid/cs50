#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    } while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    } while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // Validation for 1 and 2 cases
    if (number == 1)
    {
        return false;
    }
    if (number == 2)
    {
        return true;
    }

    // Iterate from 2 to one less than the number to find any factors
    for (int i = 2; i < number; i++)
    {
        int remainder = number % i;
        // printf("Remainder of %i with %i: %i \n", number, i, remainder);
        // Remainder of 0 indicates an integer factor therefore not prime
        if (remainder == 0)
        {
            return false;
        }
    }

    // If no factors found then there are no divisors i.e. its prime
    return true;
}