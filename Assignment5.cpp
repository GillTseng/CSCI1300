// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 5

# include <iostream>
# include <cmath>
using namespace std;


/* Part 1
* The function sum up the values in a given array
*/

float sumArray (float array[], int size)
{
    float sum=0;
    for ( int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    return sum;
}

/* Part 2
* The function is for searching position of the target value.
* If the target value is in the given array, then return the position index, if not return -1.
*/

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

/* Part 3
* The function is for calculating sum of squared difference between arrays.
* Using cmath's pow() function in calculateDifference function.
*/

float calculateDifference ( int a[], int b[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + pow(a[i]-b[i],2);
    }
    return sum;
}

/* Part 4
* The function is for sorting an ascending array in a given array by using selection sorting
*/

void sortArray (float unsortedArray[], int size)
{
    for (int i =0 ; i < size; i++) // using selection sorting
    {
        int min_value_index = i; // assume the number in index i is the smallest number
        for (int j = i+1; j < size ; j++) // compare all numbers after index i
        {
            if (unsortedArray[j] < unsortedArray[min_value_index]) // replace min_value_index with index of smaller number
            {                                                      // till the end of the array
                min_value_index = j;
            }

        }
        float temp = unsortedArray[i]; // store the index value in temp
        unsortedArray[i] = unsortedArray[min_value_index]; // swap positions of 2 numbers
        unsortedArray[min_value_index] = temp;
    }
}

/* Part 5
* The function is for copying a given array to another array.
*/

void copyArray (float source[], int size, float dest[])
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = source[i];
    }
}

/* Part 6
* The function is for converting a given integer array to a string array.
*/

void convert (int rating[], string text[], int size)
{
    int number[6] ={0,-5,-3,1,3,5}; // store all converting numbers in an integer array called number
    string str[6] = {"Not-read","Terrible","Disliked","Average","Good","Excellent"}; // store all corresponded texts in a string array called str
    string inval = "INVALID";

    for (int i = 0; i < size; i++)
    {
        int match = 0; // create a variable call 'match' to determine if numbers in rating array have any match to number array
        for (int j = 0; j < 6; j++)
        {
            if (rating[i] == number[j]) // if the number of index i matched to  numbers of index j in "number" array,
            {                           // then assign the text of index j in str into text[i]
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

/* Part 7
* The function is for finding median in a given array.
* Using functions that have been created: copyArray(...) and sortArray(...) to copy and sort the array
*/

float findMedian (float array[], int size)
{
    float new_array[size];
    copyArray(array,size,new_array);

    int median_pos = size / 2; // find median position in an array
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
