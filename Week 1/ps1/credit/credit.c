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

    // Using the fact that taking the module%10 gives last digit and diving\10 takes off the last digit
    // Note edge case of credit card starting with '0's ignores these
    int cc_length = 0;
    long cc = user_credit_number;
    bool isDouble = false; // The role of this boolean variable is to indicate whether this is a number to double or not
    int sum_of_doubled_numbers = 0;
    int sum_of_other_numbers = 0;
    while (cc > 0)
    {
        int last_digit = cc % 10; // Last digit of current cc value
        printf("last_digit %i: \n", last_digit);

        // printf("isDouble %i: \n", isDouble);

        if (isDouble == true)
        {
            int last_digit_doubled = last_digit*2;
            // In the case of doubled, we only add the individual digits of each therefore need to check if more than one digit
            int isDoubleDigit = (last_digit_doubled / 10) != 0; // We can be sure that multiple of any one digit by 2 will never yield more than two, i.e. double, digits
            if (isDoubleDigit)
            {
                int first_digit = last_digit_doubled%10; // Technically this is the second digit of the two since modulo with 10 takes from the end
                last_digit_doubled = last_digit_doubled/10; // To remove last digit
                int second_digit = last_digit_doubled%10;
                sum_of_doubled_numbers += first_digit + second_digit;
            }
            else
            {
                sum_of_doubled_numbers += last_digit * 2;
            }
            isDouble = false; // Flip isDouble
            printf("sum_of_doubled_numbers %i: \n", sum_of_doubled_numbers);
        }
        else
        {
            sum_of_other_numbers += last_digit;
            isDouble = true; // Flip isDouble
            printf("sum_of_other_numbers %i: \n", sum_of_other_numbers);
        }

        cc = cc / 10; // Divide by 10 so we lose the last digit on each iteration
        cc_length++;  // Increment length on each iteration
    }

    // Check card length and starting digits
    printf("The number of digits in your credit card number is: %i \n", cc_length);

    // Print AMEX, MASTERCARD, VISA or INVALID
    int total_sum = sum_of_doubled_numbers + sum_of_other_numbers;
    printf("sum_of_doubled_numbers %i: ", sum_of_doubled_numbers);
    printf("sum_of_other_numbers %i: ", sum_of_other_numbers);
    bool isValid = (total_sum % 10) == 0;

    if (isValid)
    {
        printf("The credit card %li is Valid.\n", user_credit_number);
    }
    else
    {
        printf("The credit card %li is Invalid.\n", user_credit_number);
    }
}