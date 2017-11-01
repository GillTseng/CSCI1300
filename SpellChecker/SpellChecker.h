// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 7
// Part 1

#ifndef SPELLCHECKER_H_INCLUDED
#define SPELLCHECKER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class SpellChecker{
    public:
        //constructor and destructor
        SpellChecker();
        SpellChecker(string);
        SpellChecker(string, string, string);
        ~SpellChecker();

        //data
        string language;

        //method
        bool readValidWords(string);
        bool readCorrectedWords(string);
        bool setStartMarker(char);
        bool setEndMarker(char);
        char getStartMarker();
        char getEndMarker();
        string repair(string);
        void repairFile(string, string);


    private:
        //data
        char start_marker;
        char end_marker;
        string valid_words[10000];
        string incorrect_words[10000];
        string correct_words[10000];
        string pun = "!@#$%^&*()_-+={}[]:;''?/<>,.";

        //method (helper function)
        string removePunLow(string);
};

#endif // SPELLCHECKER_H_INCLUDED
