// This is a solution I found in the following Medium article: https://medium.com/swlh/cs50-pset-1-credit-c7996fb0a837
// with slight refactoring here and there

#include <cs50.h>
#include <stdio.h>

long get_credit_card_number(void);
int get_cc_length(long user_cc_number);
int check_card_validity(int cc_length);
int calculate_check_sum(long user_cc_number);
int luhns_check(int check_sum);
int get_first_two_digits(long cc_number);
int check_card_type(int first_two_digits);

int main(void)
{
    long const user_credit_number = get_credit_card_number();

    int cc_length = get_cc_length(user_credit_number);

    check_card_validity(cc_length);

    int check_sum = calculate_check_sum(user_credit_number);

    luhns_check(check_sum);

    int first_two_digits = get_first_two_digits(user_credit_number);

    check_card_type(first_two_digits);
}


// -------------------------------------------------------------------
// HELPER FUNCTIONS
// -------------------------------------------------------------------

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

int get_cc_length(long user_cc_number)
{
    // Count length
    int i = 0;
    long cc = user_cc_number;
    while (cc > 0)
    {
        cc = cc / 10;
        i++;
    }
    return i;
}

int check_card_validity(int cc_length)
{
    // Check if length is valid
    if (cc_length != 13 && cc_length != 15 && cc_length != 16)
    {
        printf("INVALID due to incorrect length. \n");
        return 0;
    }
    return 1; // return 1 if passes this first stage length based validity test
}

int calculate_check_sum(long user_cc_number)
{
    // Calculate checksum
    int sum_non_doubles = 0;
    int sum_of_doubles = 0;
    long x = user_cc_number;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;
    do
    {
        // Remove last digit and add to sum_non_doubles
        mod1 = x % 10;
        x = x / 10;
        sum_non_doubles = sum_non_doubles + mod1;

        // Remove second last digit - will be doubled
        mod2 = x % 10;
        x = x / 10;
        // Double second last digit and add digits to sum_of_doubles
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum_of_doubles = sum_of_doubles + d1 + d2;

    } while (x > 0);

    total = sum_non_doubles + sum_of_doubles;

    return total;
}

int luhns_check(int check_sum)
{
    // Next check Luhn Algorithm
    if (check_sum % 10 != 0)
    {
        printf("INVALID due to failing Luhns check. \n");
        return 0;
    }
    return 1;
}

int get_first_two_digits(long cc_number)
{
    // Get starting digits
    long start = cc_number;
    do
    {
        start = start / 10;
    } while (start > 100);
    return start;
}

int check_card_type(int first_two_digits)
{
    int first_digit = first_two_digits / 10;
    int second_digit = first_two_digits % 10;

    // Next check starting digits for card type
    if ((first_digit == 5) && (0 < first_digit && second_digit < 6))
    {
        printf("MASTERCARD\n");
        return 1;
    }
    else if ((first_digit == 3) && (second_digit == 4 || second_digit == 7))
    {
        printf("AMEX\n");
        return 1;
    }
    else if (first_digit == 4)
    {
        printf("VISA\n");
        return 1;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}