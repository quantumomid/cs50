#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long user_credit_number;

    // Validation to ensure user doesn't return a negative value
    do
    {
        user_credit_number = get_long("What is your credit card number? \n");
    } while (user_credit_number < 0);

    int sum_of_doubled_numbers = 0;
    int sume_of_other_numbers = 0;

    // taking modulo with 10 gives last digit
    int last_digit = user_credit_number % 10;

    printf("The last digit of the user's credit card number is: %i \n", last_digit);

    // Check card length and starting digits

    // Print AMEX, MASTERCARD, VISA or INVALID
    
}