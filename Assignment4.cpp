// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 4


# include <iostream>
using namespace std;

float similarityScore (string sequence1, string sequence2)
{
    if ((int)sequence1.length() == (int)sequence2.length())
    {
        int i =0;
        float num_match =0;
        float len = sequence1.length();
        while (i < len)
        {
            if (sequence1[i] == sequence2[i])
            {
                num_match++;
            }
            i++;
        }
        return num_match / len;
    }
    else
    {
        return 0;
    }
}


int countMatches (string genome, string sequence1 , float min_score)
{

    int i = 0;
    float len = sequence1.length();
    int count = 0;
    float simi_score;
    while ((i+len) <= (int)genome.length())
    {
        simi_score = similarityScore( genome.substr(i,len),sequence1);
        if (simi_score > min_score)
        {
            count++;
        }
        i++;
    }
    return count;
}


float findBestMatch (string genome, string seq)
{
    float highest_score =0;
    float score;
    int i = 0;
    int len = seq.length();
    while ( (i+len) < (int)genome.length())
    {
        score = similarityScore(genome.substr(i,len),seq);
        if ( score > highest_score)
        {
            highest_score = score;
        }
        i++;
    }
    return highest_score;
}

int findBestGenome (string genome1, string genome2, string genome3, string seq)
{
    float highest_1 = findBestMatch(genome1,seq);
    float highest_2 = findBestMatch(genome2,seq);
    float highest_3 = findBestMatch(genome3,seq);
    if ( highest_1 > highest_2 && highest_1 > highest_3 )
    {
        return 1;
    }
    if ( highest_2 > highest_1 && highest_2 > highest_3 )
    {
        return 2;
    }
    if ( highest_3 > highest_1 && highest_3 > highest_2 )
    {
        return 3;
    }
    else
    {
        return 0;
    }

}
