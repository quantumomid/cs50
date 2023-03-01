#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_grid(int size);

int main(void)
{

    // Get height of grid
    int n = get_height();

    // Print grid of bricks
    print_grid(n);
}

int get_height(void)
{
    // declare variable without any assignment
    int n;

    // Validation to ensure height is between 1 and 8
    do
    {
        n = get_int("Choose the height for the pyramind (between 1 and 8)? \n");
    } while (n < 1 || n > 8);

    return n;
}

// When printing a pyramid, i.e. of size 4, you have 1# in zero row, 2# in first, 3# in second and 4# in third
void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}