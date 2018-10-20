/*
Problem Set 1 credit.c
This program determines whether a provided credit card number is valid.
Heero van der Veen 2017
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long ccard, count;
    int sum = 0, mod, amex, master, visa16, visa13;

    //Get user input that is not negative
    do
    {
        printf("credit card number: \n");
        ccard = get_long_long();
    }
    while(ccard <= 0 );

    //Calculating the first part of Luhn’s algorithm while keep the sum of digits.
    count = ccard / 10;
    do
    {
        mod = count % 10;
        mod = mod * 2;
        if (mod > 9)
            mod = (mod % 10) + (mod / 10);
        sum = sum + mod;
        count = count / 100;
    }
    while( count != 0);

    //Calculating the second part of Luhn’s algorithm while keep the sum of digits.
    count = ccard;
    do
    {
        mod = count % 10;
        sum = sum + mod;
        count = count / 100;
    }
    while( count != 0);

    //Getting start numbers for matching CC brands
    amex = ccard / 10000000000000;
    master = ccard / 100000000000000;
    visa16 = ccard / 1000000000000000;
    visa13 = ccard / 1000000000000;

    //Check if the card number is valid
    if (sum % 10 == 0)
    {
        if (amex == 34 || amex == 37)
            printf("AMEX\n");
        if (master >= 51 && master <= 55)
            printf("MASTERCARD\n");
        if (visa16 == 4 || visa13 == 4)
            printf("VISA\n");
    }
    else
        printf("INVALID\n");
}
