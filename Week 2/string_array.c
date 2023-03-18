// Use concept of arrays with strings
#include <cs50.h>
#include <stdio.h>

int main (void) {

    // Initialising/declaring an Array, where the 
    // individual elements are strings
    string words[2];

    words[0] = "Rick";
    words[1] =  "Grimes";

    printf("Where is %s %s??? \n", words[0], words[1]);
}