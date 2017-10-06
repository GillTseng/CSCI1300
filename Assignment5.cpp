// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 5

# include <iostream>
# include <cmath>
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
        sum = sum + pow(a[i]-b[i],2);
    }
    return sum;
}

// Part 4

void sortArray (float unsortedArray[], int size)
{
    for (int i =0 ; i < size; i++)
    {
        int min_value_index = i;
        for (int j = i+1; j <= size-i ; j++) //find the smallest value in the array
        {
            if (unsortedArray[j] < unsortedArray[min_value_index])
            {
                min_value_index = j;
            }
        }
        cout << unsortedArray[min_value_index] << endl;
        //float temp = unsortedArray[i];
        //unsortedArray[i] == unsortedArray[min_value_index];
        //unsortedArray[min_value_index] == temp;
    }
}
