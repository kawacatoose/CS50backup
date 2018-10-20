/*
Problem Set 2 Ceasar
A program that encrypts with caesar's cipher.
Heero van der Veen * 2017
*/

#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LOWERASCII 97
#define UPPERASCII 65
#define ALPHABET 26

string encrypt( string text, int cipher );
char encryptchar( char letter, int cipher, int ascii );

int main(int argc, string argv[])
{
    //Check for command line input. If valid then execute program or else end program.
    if ( argc >= 2 )
    {
        //Make the cipher value an integer.
        int cipher = atoi(argv[1]);

        //Get user input for the plain text.
        printf("Plaintext: ");
        string plaintext = get_string();

        //call encrypt function and print results.
        string ciphertext = encrypt( plaintext, cipher );
        printf("ciphertext: %s\n", ciphertext);
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return( argc );
    }
}

string encrypt( string text, int cipher )
{
    /*
    Create a loop from de length of the string and then itterate on each char
    if its alpha and then upper or lower case and if so encrypt char.
    */

    int length = strlen( text );
    for ( int position = 0; position < length; position++ )
    {
        if isalpha( text[position] )
        {
            if islower( text[position] )
            {
                text[position] = encryptchar( text[position], cipher, LOWERASCII );
            }
            if isupper( text[position] )
            {
                text[position] = encryptchar( text[position], cipher, UPPERASCII );
            }
        }
    }
    return( text );
}

char encryptchar( char letter, int cipher, int ascii )
{
    //Change char from ASCII to alphabetical index.
    letter = letter - ascii;

    //Add cipher to char and then keep it within the amount of letters of the alphabet.
    letter = ( letter + cipher ) % ALPHABET;

    //Change back to ascii.
    letter = letter + ascii;
    return( letter );
}
