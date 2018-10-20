/*
Problem Set 2 Vigenere
A program that encrypts with Vigenere's cipher.
Made some changes from caesar by putting de calculation in one line.
Heero van der Veen 2017
*/

#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LOWERASCII 97
#define UPPERASCII 65
#define ALPHABET 26

string encrypt( string text, string key );
bool checkalpha( string key);

int main(int argc, string argv[])
{
    //Check for command line input. If valid then execute program or else end program.
    if ( argc == 2 && checkalpha( argv[1] ))
    {
        //Get user input for the plain text.
        printf("Plaintext: ");
        string plaintext = get_string();

        //call encrypt function and print results.
        printf("ciphertext: %s\n", encrypt( plaintext, argv[1] ));

    }
    else
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
}

string encrypt( string text, string key )
{
    //Create a variable for checking key position.
    int keypos=0;
    //Get the length of the strings
    int keylength=strlen(key);
    int textlength=strlen(text);
    //Create a loop from de length of the string and then iterate on each character.
    for ( int pos = 0; pos < textlength; pos++ )
    {
        //Check of character is a letter.
        if isalpha( text[pos] )
        {
            //Check if letter is lower case.
            if islower( text[pos] )
            {
               //Letter in the string at current position gets shifted to alpabetical index.
               //To get the right key letter. The key position gets modulo operation with the key length.
               //The key letter get changed to uppercase and shifted to alphabetical index.
               //Letter adds to the Key and the result get's modulo operation with the amount of letters in the alphabet.
               //Result get shifted back to ASCII and you have the encoded letter.
               text[pos] = (((text[pos] - LOWERASCII) + (toupper(key[keypos % keylength]) - UPPERASCII)) % ALPHABET) + LOWERASCII;
            }
            //Check if letter is upper case.
            if isupper( text[pos] )
            {
                text[pos] = (((text[pos] - UPPERASCII) + (toupper(key[keypos % keylength]) - UPPERASCII)) % ALPHABET) + UPPERASCII;
            }
            //Adds 1 to key position.
            keypos++;
        }
    }
    return( text );
}

bool checkalpha( string s )
{
    //Get the length of a string
    int length = strlen( s );
    //Make a loop to check if every char in string is a letter
    for (int i=0; i < length; i++ )
    {
        if ( isalpha( s[i] ) == false )
        {
            return( false );
        }
    }
    return( true );
}
