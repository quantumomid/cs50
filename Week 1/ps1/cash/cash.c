#include <cs50.h>
#include <stdio.h>

// Declare functions used in the program
/**
 * Prompts the user for the number of cents they are owed.
 *
 * @return The number of cents the user is owed as an integer.
 */
int get_cents(void);

/**
 * Calculates the number of quarters to return to the customer.
 *
 * @param cents The total number of cents owed to the customer.
 * @return The number of quarters to return as an integer.
 */
int calculate_quarters(int cents);

/**
 * Calculates the number of dimes to return to the customer.
 *
 * @param cents The total number of cents owed to the customer.
 * @return The number of dimes to return as an integer.
 */
int calculate_dimes(int cents);

/**
 * Calculates the number of nickels to return to the customer.
 *
 * @param cents The total number of cents owed to the customer.
 * @return The number of nickels to return as an integer.
 */
int calculate_nickels(int cents);

/**
 * Calculates the number of pennies to return to the customer.
 *
 * @param cents The total number of cents owed to the customer.
 * @return The number of pennies to return as an integer.
 */
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    printf("Number of Quarters returned: %i\n", quarters);

    // Subtract the value of quarters given from the total amount of cents owed
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    printf("Number of Dimes returned: %i\n", dimes);

    // Subtract the value of dimes given from the total amount of cents owed
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    printf("Number of Nickels returned: %i\n", nickels);

    // Subtract the value of nickels given from the total amount of cents owed
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    printf("Number of Pennies returned: %i\n", pennies);

    // Subtract the value of pennies given from the total amount of cents owed
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("Total number of all coins returned is therefore: %i\n", coins);
}

int get_cents(void)
{
    int n;

    // Validation to ensure user doesn't return a negative value
    do
    {
        n = get_int("How many cents are you owed? \n");
    } while (n < 0);

    return n;
}

int calculate_quarters(int cents)
{
    // We return the integer of how many times 25 goes into the cents argument
    int no_of_quarters = cents / 25;
    return no_of_quarters;
}

int calculate_dimes(int cents)
{
    int no_of_dimes = cents / 10;
    return no_of_dimes;
}

int calculate_nickels(int cents)
{
    int no_of_nickels = cents / 5;
    return no_of_nickels;
}

int calculate_pennies(int cents)
{
    // Just need to return the number of cents since a penny is 1c
    return cents;
}
