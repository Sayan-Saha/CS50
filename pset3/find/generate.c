/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT], one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Checking and terminating the programme if the input arguents are not 2 or 3..The condition will be true if the input arguments are neither 2 nor 3..
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Taking the number of pseudorandom numbers to print by converting the 2nd argument to integer..
    int n = atoi(argv[1]);

    // If seed value is available generates same uniformly distributed random numbers for every run time based on the seed..Otherwise generates random numbers every time.. 
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Print n times a random number based on the limit given..all generated numbers have the max limit as given..
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
