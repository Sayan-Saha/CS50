/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    for(int i=0; i<n; i++)
    {
     if( values[i] == value )
     {
      return true;
     } 
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int swap = 0;
    for(int i=0; i<n; i++)
    {
     for(int j=0; j<n-i; j++)
     {
      if ( values[j]>values[j+1] )
      {
       swap= values[j+1];
       values[j+1]=values[j];
       values[j]=swap;
      }
     }
    }
}
