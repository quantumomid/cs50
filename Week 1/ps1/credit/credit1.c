// My solution but refactored with tips from ChatGPT!
// For example: using separate functions to perform distinct tasks, use snake_casing when naming variables, etc.

#include <cs50.h>
#include <stdio.h>

long get_credit_card_number(void);
int calculate_sum_of_cc_luhns(long user_cc_number);
int get_cc_length(long user_cc_number);
int check_card_validity_and_type(bool is_valid, long user_cc_number, int cc_length);

int main(void)
{
    long const user_credit_number = get_credit_card_number();

    // Iterate through digits of credit card number
    // and compute sum of digits to determine if valid
    int cc_length = get_cc_length(user_credit_number);

    // Determine if the credit card number is valid
    int total_sum = calculate_sum_of_cc_luhns(user_credit_number);

    bool is_valid = (total_sum % 10) == 0;

    check_card_validity_and_type(is_valid, user_credit_number, cc_length);
}

// Use 'long' since return type is long - will get errors if use 'int'
// since need to tell computer we will need th extra memory space!
long get_credit_card_number(void)
{
    long user_credit_number;

    // Prompt user for credit card number and ensure non-negative input
    do
    {
        user_credit_number = get_long("What is your credit card number? \n");
    } while (user_credit_number < 0);
    return user_credit_number;
}

int calculate_sum_of_cc_luhns(long user_cc_number)
{
    // Iterate through digits of credit card number
    // and compute sum of digits to determine if valid
    long cc = user_cc_number;
    bool is_double = false; // flag for whether to double the next digit
    int sum_of_doubled_numbers = 0;
    int sum_of_other_numbers = 0;
    while (cc > 0)
    {
        int last_digit = cc % 10; // Get the rightmost digit

        // If current digit is one that should be doubled
        if (is_double == true)
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
            is_double = false;
        }
        else
        {
            sum_of_other_numbers += last_digit;
            // Reset flag
            is_double = true;
        }

        // Remove rightmost digit from number
        cc = cc / 10;
    }

    // Determine if the credit card number is valid
    int total_sum = sum_of_doubled_numbers + sum_of_other_numbers;
    return total_sum;
}

int get_cc_length(long user_cc_number)
{
    int cc_length = 0;
    long cc = user_cc_number; // Use dereference operator to access value to avoid modifying original
    while (cc > 0)
    {
        // Remove rightmost digit from number
        cc = cc / 10;

        // Increment counter for number of digits processed
        cc_length++;
    }
    return cc_length;
}

int check_card_validity_and_type(bool is_valid, long user_cc_number, int cc_length)
{
    // Print results based on validity and type of credit card
    if (is_valid)
    {
        printf("The credit card %li is Valid.\n", user_cc_number);

        // Check length and first digits to determine type of card
        if (cc_length == 16)
        {
            int first_two_digits = user_cc_number / 100000000000000;
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
            int first_digit = user_cc_number / 100000000000; // For VISA need first digit
            printf("First digit of the credit card is: %i \n", first_digit);

            if (first_digit == 4)
            {
                printf("VISA \n");
            }
        }
        else if (cc_length == 15)
        {
            int first_two_digits = user_cc_number / 10000000000000;
            printf("First two digit of the credit card is: %i \n", first_two_digits);

            if (first_two_digits == 34 || first_two_digits == 37)
            {
                printf("AMEX \n");
            }
        }
        return 1;
    }
    else
    {
        printf("The credit card %li is Invalid.\n", user_cc_number);
        return 0;
    }
}