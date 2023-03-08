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

    // Using the fact that taking the module%10 gives last digit and
    // dividing\10 takes off the last digit
    // Note edge case of credit card starting with '0's ignores these
    int cc_length = 0;
    long cc = user_credit_number;
    // The role of this boolean variable is to indicate whether this is a number to double or not
    bool isDouble = false;
    int sum_of_doubled_numbers = 0;
    int sum_of_other_numbers = 0;
    while (cc > 0)
    {
        int last_digit = cc % 10; // Last digit of current cc value
        printf("last_digit %i: \n", last_digit);

        // In the case of doubled, we only add the INDIVIDUAL digits therefore
        // need to take care when the last digit doubles is two digits
        if (isDouble == true)
        {
            int last_digit_doubled = last_digit * 2;
            int isDoubleDigit = (last_digit_doubled / 10) != 0; // We can be sure that multiple of any one digit by 2 will never yield more than two, i.e. double, digits
            if (isDoubleDigit)
            {
                int first_digit = last_digit_doubled % 10;    // Technically this is the second digit of the two since modulo with 10 takes from the end
                last_digit_doubled = last_digit_doubled / 10; // To remove last digit
                int second_digit = last_digit_doubled % 10;
                sum_of_doubled_numbers += first_digit + second_digit;
            }
            else
            {
                sum_of_doubled_numbers += last_digit * 2;
            }
            isDouble = false; // Flip isDouble
        }
        else
        {
            sum_of_other_numbers += last_digit;
            isDouble = true; // Flip isDouble
        }

        cc = cc / 10; // Divide by 10 so we lose the last digit on each iteration
        cc_length++;  // Increment length on each iteration
    }

    // Check card length and starting digits
    printf("The number of digits in your credit card number is: %i \n", cc_length);

    // Print AMEX, MASTERCARD, VISA or INVALID
    int total_sum = sum_of_doubled_numbers + sum_of_other_numbers;
    bool isValid = (total_sum % 10) == 0;

    if (isValid)
    {
        printf("The credit card %li is Valid.\n", user_credit_number);
        if (cc_length == 16)
        {
            int first_two_digits = user_credit_number / 100000000000000;
            int first_digit = first_two_digits / 10; // For VISA need first digit
            printf("First two digit of the credit card is: %i \n", first_two_digits);

            if (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 || first_two_digits == 55)
            {
                printf("MASTERCARD \n");
            }
            if (first_digit == 4)
            {
                printf("VISA \n");
            }
        }
        if (cc_length == 13)
        {
            int first_digit = user_credit_number / 100000000000; // For VISA need first digit
            printf("First digit of the credit card is: %i \n", first_digit);

            if (first_digit == 4)
            {
                printf("VISA \n");
            }
        }
        if (cc_length == 15)
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