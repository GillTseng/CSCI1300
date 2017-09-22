// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 4


# include <iostream>
using namespace std;

float similarityScore (string sequence1, string sequence2)
{
    if (sequence1.length() == sequence2.length())
    {
        int i =0;
        int num_match =0;
        while (i < sequence1.length())
        {
            if (sequence1[i] == sequence2[i])
            {
                num_match = num_match+1;
            }
        }
    }
    else
    {
        return 0;
    }
}
