// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 5

# include <iostream>
# incldue <cmath>
using namespace std;


// Part 1

float sumArray (float array[], int size)
{
    float sum=0;
    for ( int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    return sum;
}

// Part 2

int Search ( int array[], int size, int target)
{

    int num =0;
    for ( int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            num++;
            return i;
        }
    }
    if (num == 0)
    {
        return -1;
    }
}

// Part 3

float calculateDifference ( int a[], int b[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {

    }
}
