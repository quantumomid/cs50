#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    printf("Number of Quarters returned: %i\n", quarters);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    printf("Number of Dimes returned: %i\n", dimes);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    printf("Number of Nickels returned: %i\n", nickels);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    printf("Number of Pennies returned: %i\n", pennies);
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
