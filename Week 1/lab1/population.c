// Import the necessary libraries
#include <cs50.h> // for using get_int() function
#include <stdio.h> // for using printf() function

int main(void)
{
    // Declare variables
    int llamas_initial;

    // Ensure user chooses an initial value greater than 8
    do
    {
        llamas_initial = get_int("Choose a initial population number of llamas? (minimum is 9) \n");
    } while (llamas_initial < 9);

    int llamas_final;

    // Ensure user chooses a final value greater than the initial value they chose
    do
    {
        llamas_final = get_int("Choose a final population number of llamas? (must be larger than your previous response for the initial population.) \n");
    } while (llamas_final < llamas_initial);

    // Declare and initialize additional variables
    int llamas_growing = llamas_initial;
    int no_years = 0;

    // Loop until the final number of llamas is reached
    while (llamas_growing < llamas_final)
    {
        // Calculate the growing population of llamas each year
        llamas_growing = llamas_growing - llamas_growing / 4 + llamas_growing / 3;
        // Increment the number of years it takes for the llamas to reach the final number
        no_years++;
    }

    // Display the result of the calculation
    printf("It will take %i number of years to reach a final population of %i from an initial population of %i. \n", no_years, llamas_initial, llamas_final);
} 

/*
This program calculates the number of years it takes for a population of llamas to grow from an initial number to a final number, based on a growth formula. It ensures that the user inputs an initial number greater than 8 and a final number greater than the initial number. The program then loops until the final number of llamas is reached, incrementing the number of years it takes to reach that number. Finally, it outputs the result of the calculation to the user.
*/
