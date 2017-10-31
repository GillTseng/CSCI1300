#ifndef WORDCOUNTS_INCLUDED
#define WORDCOUNTS_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class WordCounts{
    public:
        //constructor
        WordCounts();
        ~WordCounts();

        //method
        void tallyWords(string);
        int getTally(string);
        void resetTally();
        int mostTimes(string[], int[], int);


    private:
        //data
        string words[10000];
        int count[10000];

        //method
        string removePunLow(string);

};


#endif // WORDCOUNTS_INCLUDED
