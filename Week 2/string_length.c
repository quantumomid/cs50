// How to work out length of a string?
// Use <string.h> library
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    string first_name = get_string("What is your first name? \n");

    int name_length = strlen(first_name);

    printf("The length of your first name, %s, is %i. \n", first_name, name_length);
}

// MANUALLY
// Use the fact that '/0' is used by the
// computer to mark the end of the string

// #include <cs50.h>
// #include <stdio.h>

// int main(void)
// {

//     string first_name = get_string("What is your first name? \n");

// Count number of characters up until '\0' (aka NUL)
//     int l = 0; // initialise an index to traverse sting (which is an array of characters)
//     while (first_name[l] != '/0')
//     {
//         l++;
//     }

//     printf("The length of your first name, %s, is %i. \n", first_name, l);
// }