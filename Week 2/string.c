// A string is simply an array of variables of type char (character)

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "OMID";
    // Here we print as integer i.e. %i there its the
    // decimal representation of the characters that is printed
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);

    printf("%c %c %c %c\n", s[0], s[1], s[2], s[3]); // this will print actual characters!
}