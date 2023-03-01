#include <cs50.h>
#include <stdio.h>

// function prototypes - to let compiler know
int get_height(void);
void print_grid(int size);

int main(void)
{
    // get height of pyramid from user input
    int n = get_height();

    // print pyramid
    print_grid(n);
}

// prompt user for pyramid height between 1 and 8 (inclusive)
int get_height(void)
{
    int n;

    do
    {
        n = get_int("Choose the height for the pyramind (between 1 and 8)? \n");
    } while (n < 1 || n > 8);

    return n;
}

// print pyramid of '#' symbols with given height
void print_grid(int size)
{
    // iterate over each row of the pyramid
    for (int i = 0; i < size; i++)
    {
        // print spaces before '#' symbols
        for (int j = 0; j < size - i; j++)
        {
            printf(" ");
        }

        // print '#' symbols
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        
        // move to next line after each row is printed
        printf("\n");
    }
}