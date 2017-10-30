#include <iostream>
#include <string>
#include <fstream>
#include "SpellChecker.h"
using namespace std;

SpellChecker::SpellChecker(){

}

SpellChecker::SpellChecker(string lan){
    language = lan;
}

//SpellChecker::SpellChecker(string lan, string validfile, string correctfile){
//    language = lan;
//    readValidWords(validfile);
//    readCorrectedWords(correctfile);
//}

SpellChecker::~SpellChecker(){

}

bool SpellChecker::readValidWords(string validfile){
    ifstream inStream (validfile, ios::in);
    if (!inStream.is_open()){
        return inStream.is_open();
    }

    while(getline(inStream,line)){
        if(line.length()>0){
                valid_words[count] = line;
                count++;
        }
    }
    inStream.close();
    return count != 0;
}

bool SpellChecker::readCorrectedWords(string correctfile){
    ifstream inStream (correctfile,ios::in);
    if (!inStream.is_open()){

    }
}
