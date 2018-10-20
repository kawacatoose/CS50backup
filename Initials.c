/*
Problem Set 2 Initials more
A program to print initials from a given name
Heero van der Veen 2017
*/


#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //prompting user for input
    string name=get_string();

    //A loop in the length of string
    for (int i=0; i < strlen(name); i++)
    {
        //Only print the first letter of each word in caps
        if ((i == 0 && name[i] != 32) || (name[i-1] == 32 && name[i] != 32))
            printf("%c", toupper(name[i]));
    }

    //Give a new line at the end
    printf("\n");
}
