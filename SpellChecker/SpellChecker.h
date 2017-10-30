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
        void getStartMarker();
        void getEndMarker();
        string repair(string);
        void repairFile(string, string);


    private:
        //data
//        string valid_spell_file;
//        string miss_spell_file;
        char start_marker;
        char end_marker;
        string valid_words[10000];
        string correct_words[10000];
        string incorrect_words[10000];
        string line;
        int count =0;
//        string input_file;
//        string output_file;

};

#endif // SPELLCHECKER_H_INCLUDED
