// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 4


# include <iostream>
using namespace std;


/*
* The function is to calculate similarity score of 2 sequences
* First, the 2 sequences should be in the same length.
* Second, compare character by character and sum up how many character matched to each other.
* Then, similarity score = sum number of matched character / sequence length.
*/

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


/*
* The function is to count how many sequences match to genome on a certain or greater similarity score
* by leverage previous similarityScore(...) function.
* First, calculate the similarity scores in genome in a giving sequence length.
* Second, compare the similarity scores with the one that have been given (min_score).
* If similarity score is greater or equal than minimum score, it will be counted in one match.
*/

int countMatches (string genome, string sequence1 , float min_score)
{

    float len = sequence1.length();
    float simi_score;
    int count = 0;
    int i = 0;
    while ((i+len) <= (int)genome.length())
    {
        simi_score = similarityScore( genome.substr(i,len),sequence1);
        if (simi_score >= min_score)
        {
            count++;
        }
        i++;
    }
    return count;
}



/*
* The function is to find the best similarity score in a given genome.
* First, using the previous function similarityScore(...) to calculate similarity score in a giving sequence length.
* If the latest similarity score is greater than previous one, then keep the latest score.
* In the end, the function return the highest similarity score.
*/

float findBestMatch (string genome, string seq)
{
    float highest_score =0;
    float score;
    int i = 0;
    int len = seq.length();
    while ( (i+len) <= (int)genome.length())
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

/*
* The function is to find which genome has better match to the sequence.
* Leverage previous function findBestMatch(...) to calculate highest similarity score in each genome.
* Then compare those 3 scores and return the highest one in integer format.
*/

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
