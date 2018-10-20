/*
Problem set 1 mario.c, more comfortable.
Draw a Mario like pyramid.
Heero van der Veen 2017
*/

#include <cs50.h>
#include <stdio.h>

void draw_hash(int line);
int height;

int main(void)
{
    //Get user input that is between 0 and 23
    do
    {
        printf ("Height: ");
        height = get_int();
    }
    while ( height < 0 || height > 23 );

    //Draw the pyramid.
    for ( int line = 0; line < height; line++ )
    {
        for ( int space = 1; space < height - line; space++ )
        {
            printf(" ");
        }

        draw_hash(line);

        printf ("  ");

        draw_hash(line);

        printf ("\n");
    }
}

//Draw the number of hashes needed for each line.
void draw_hash(int line)
{
   for ( int hash = -1; hash < line; hash++ )
        {
            printf ("#");
        }
}
