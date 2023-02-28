#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user to agree or disagree
    char x = get_char("Do you agree? \n");

    // Check whether agreed or not
    if (x == 'y' || x == 'Y')
    {
        printf("Yes, agreed!");
    }
    else if (x == 'N' || x == 'N')
    {
        printf("No, not agreed!");
    }
}