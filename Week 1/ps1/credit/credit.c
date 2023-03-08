// MY solution
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long user_credit_number;

    // Prompt user for credit card number and ensure non-negative input
    do
    {
        user_credit_number = get_long("What is your credit card number? \n");
    } while (user_credit_number < 0);

    // Iterate through digits of credit card number
    // and compute sum of digits to determine if valid
    int cc_length = 0;
    long cc = user_credit_number;
    bool isDouble = false; // flag for whether to double the next digit
    int sum_of_doubled_numbers = 0;
    int sum_of_other_numbers = 0;
    while (cc > 0)
    {
        int last_digit = cc % 10; // Get the rightmost digit

        // If current digit is one that should be doubled
        if (isDouble == true)
        {
            int last_digit_doubled = last_digit * 2;

            // If doubling creates two digits, add them individually
            if (last_digit_doubled >= 10)
            {
                int first_digit = last_digit_doubled % 10; // second digit (from right)

                last_digit_doubled = last_digit_doubled / 10; // To remove last digit

                int second_digit = last_digit_doubled % 10; // first digit (from right)
                sum_of_doubled_numbers += first_digit + second_digit;
            }
            else
            {
                sum_of_doubled_numbers += last_digit * 2;
            }

            // Reset flag
            isDouble = false;
        }
        else
        {
            sum_of_other_numbers += last_digit;
            // Reset flag
            isDouble = true;
        }

        // Remove rightmost digit from number
        cc = cc / 10;

        // Increment counter for number of digits processed
        cc_length++;
    }

    // Determine if the credit card number is valid
    int total_sum = sum_of_doubled_numbers + sum_of_other_numbers;
    bool isValid = (total_sum % 10) == 0;

    // Print results based on validity and type of credit card
    if (isValid)
    {
        printf("The credit card %li is Valid.\n", user_credit_number);

        // Check length and first digits to determine type of card
        if (cc_length == 16)
        {
            int first_two_digits = user_credit_number / 100000000000000;
            int first_digit = first_two_digits / 10; // For VISA need first digit
            printf("First two digit of the credit card is: %i \n", first_two_digits);

            if (first_two_digits >= 51 && first_two_digits <= 55)
            {
                printf("MASTERCARD \n");
            }
            else if (first_digit == 4)
            {
                printf("VISA \n");
            }
        }
        else if (cc_length == 13)
        {
            int first_digit = user_credit_number / 100000000000; // For VISA need first digit
            printf("First digit of the credit card is: %i \n", first_digit);

            if (first_digit == 4)
            {
                printf("VISA \n");
            }
        }
        else if (cc_length == 15)
        {
            int first_two_digits = user_credit_number / 10000000000000;
            printf("First two digit of the credit card is: %i \n", first_two_digits);

            if (first_two_digits == 34 || first_two_digits == 37)
            {
                printf("AMEX \n");
            }
        }
    }
    else
    {
        printf("The credit card %li is Invalid.\n", user_credit_number);
    }
}