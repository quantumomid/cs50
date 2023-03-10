#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int size);

int main(void)
{

    // Get size of grid
    int n = get_size();

    // Print grid of bricks
    print_grid(n);
}




int get_size(void)
{
    // declare variable without any assignment
    int n;

    // For validation => keep asking user if they respond with a non-integer response
    do
    {
        n = get_int("Choose a number? ");
    } while (n <= 0);

    return n;
}

void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}