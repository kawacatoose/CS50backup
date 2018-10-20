/*
Problem set 1 water.c
Program converts minutes water usages to the amount of bottles.
Heero van der Veen 2017
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Minutes: ");
    int minutes = get_int();
    printf("Bottles: %i\n", minutes * 12);
}
