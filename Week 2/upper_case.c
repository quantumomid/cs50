// Using ctype.h library
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");

    // Iterate through each character of the string s and 
    // print character if lower case otherwise convert to 
    // upper case and print
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}


// MANUALLY - if you had to create your own program to convert a string to uppercase:
// This code iterates through each value in the string. The program looks at each character. 
// If the character is lowercase, it subtracts the value 32 from it to convert it to lowercase.
// This is leveraging symmetry between lower and upper case values in ASCII, i.e. When a lowercase 
// character has 32 subtracted from it, it results in an uppercase version of that same character.
// #include <cs50.h>
// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     string s = get_string("Before: ");
//     printf("After:  ");
//     for (int i = 0, n = strlen(s); i < n; i++)
//     {
//         if (s[i] >= 'a' && s[i] <= 'z')
//         {
//             printf("%c", s[i] - 32);
//         }
//         else
//         {
//             printf("%c", s[i]);
//         }
//     }
//     printf("\n");
// }