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

int search ( int array[], int size, int target)
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
    for (int i =0 ; i < size; i++) // using selection sorting
    {
        int min_value_index = i; // assume the index number is the smallest number
        for (int j = i+1; j < size ; j++) //compare all numbers after the index value
        {
            if (unsortedArray[j] < unsortedArray[min_value_index]) //replace previous index with index of smallest number
            {
                min_value_index = j;
            }

        }
        float temp = unsortedArray[i]; //swap positions of 2 numbers
        unsortedArray[i] = unsortedArray[min_value_index];
        unsortedArray[min_value_index] = temp;
    }
}

// Part 5

void copyArray (float source[], int size, float dest[])
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = source[i];
    }
}

// Part 6

void convert (int rating[], string text[], int size)
{
    int number[6] ={0,-5,-3,1,3,5};
    string str[6] = {"Not-read","Terrible","Disliked","Average","Good","Excellent"};
    string inval = "INVALID";

    for (int i = 0; i < size; i++)
    {
        int match = 0;
        for (int j = 0; j < 6; j++)
        {
            if (rating[i] == number[j])
            {
                text[i]= str[j];
                match++;
            }
        }
        if (match == 0)
        {
            text[i] = inval;
        }
    }
}

// Part 7
// know how many number you should count till the median (median_order)
// find the smallest number then count++, find second smallest number then count++ when count == median_order you find the median


float findMedian (float array[], int size)
{
    float new_array[size];
    copyArray(array,size,new_array);
    int median_pos = size / 2;
    sortArray(new_array,size);

    if ( size % 2 ==1) //determine if the size is even or odd
    {
        return new_array[median_pos];
    }

    else
    {
         return (new_array[median_pos]+new_array[median_pos-1])/2;
    }
}
