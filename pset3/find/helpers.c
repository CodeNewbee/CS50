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
    int mid = (n / 2);
    int minVal = 0;
    int maxVal = n - 1;
    //return false if size isn't positive
    while (n > 0)
    {
        n = n - (n / 2) - (n % 2);
        if (values[mid] == value)
        {
            return true;
        }
        else if (values[mid] < value)
        {
            minVal = mid + 1;
            mid = (maxVal - (minVal + 1))/2 + minVal;
        }
        else if (values[mid] > value)
        {
            maxVal = mid;
            mid = (maxVal-minVal)/2;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        short swap = 0;
        //initialize min value to leftmost value of unsorted array
        int minValueIndex = i;
        //search for smallest val in unsorted array
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < values[minValueIndex])
            {
                minValueIndex = j;
                swap = 1;
            }
        }
        if (swap == 0) 
        {
            return;
        }
        else
        {
            //swamp min and leftmost values of unsorted array
            int minVal = values[minValueIndex];
            values[minValueIndex] = values[i];
            values[i] = minVal;
            swap = 0;
        }
    }
    return;
}