// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 7
// Part 1

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

SpellChecker::SpellChecker(string lan, string validfile, string correctfile){
    language = lan;
    readValidWords(validfile);
    readCorrectedWords(correctfile);
}

SpellChecker::~SpellChecker(){

}

// the function read valid words file
bool SpellChecker::readValidWords(string validfile){
    ifstream inStream (validfile, ios::in);
    if (!inStream.is_open()){                               // check if the file open successfully
        return inStream.is_open();
    }

    string line;
    int count = 0;
    while(getline(inStream,line)){
        if(line.length()>0){                                // if line is not blank then move one to next line
                valid_words[count] = line;                  // store line into valid_words array
                count++;
        }
    }
    inStream.close();
    return count != 0;
}

// the function read miss spelled words file
bool SpellChecker::readCorrectedWords(string correctfile){
    ifstream inStream (correctfile,ios::in);
    if (!inStream.is_open()){                               // check if the file open successfully
        return inStream.is_open();
    }

    string line;
    int pos = 0;                                            // create an int variable 'pos' to store tab position
    while(getline(inStream,line)){
        if(line.length()>0){                                // if line is not blank then move one to next line
                pos = line.find('\t');                      // find the tab position and store it in 'pos'
                for (int i = 0; i < 10000; i++){            // determine where to append the line to the existing array
                    if(incorrect_words[i].length() == 0){
                        incorrect_words[i] = line.substr(0,pos);
                        correct_words[i] = line.substr(pos+1,line.length()-(pos+1));
                        break;
                    }
                }

        }
    }
    inStream.close();
    return pos != 0;
}

// input a character to set start marker
bool SpellChecker::setStartMarker(char startmkr){
    start_marker = startmkr;
    return start_marker == startmkr;
}

// input a character to set end marker
bool SpellChecker::setEndMarker(char endmkr){
    end_marker = endmkr;
    return end_marker == endmkr;
}

// return start marker
char SpellChecker::getStartMarker(){
    return start_marker;
}

// return end marker
char SpellChecker::getEndMarker(){
    return end_marker;
}

// the function is a helper function to remove punctuation at both ends of the string and then turn upper case to lower case
string SpellChecker::removePunLow(string sent){

    // if the first position of the string is punctuation, remove it
    for (int i = 0; i < pun.length(); i++){
        if(sent[0] == pun[i]){
            sent = sent.substr(1,sent.length()-1);
            break;
        }
    }

    // if the last position of the string is punctuation, remove it
    for (int j = 0; j < pun.length(); j++){
        if(sent[sent.length()-1] == pun[j]){
            sent = sent.substr(0,sent.length()-1);
            break;
        }
    }

    // if the character is upper case turn into lower case
    for (int k = 0; k < sent.length(); k++){
        if (sent[k] >= 'A' && sent[k] <='Z'){
            sent[k] = (char)tolower(sent[k]);
        }
    }
    return sent;
}

// the function is for fixing input string
string SpellChecker::repair(string sentence){
    string new_line;
    string substring;
    int count = 0;
    for (int i = 0; i < sentence.length(); i++){                // if the sentence[i] is not space then append the sentence[i] to substring
        if(sentence[i] != ' '){
            substring = substring + sentence[i];
        }
        if (sentence[i] ==' ' || i == sentence.length()-1){
            bool is_valid = false;
            substring = removePunLow(substring);                // remove punctuation and lower cases for the parsing word
            for(int j = 0; j < 10000; j++){                     // compare the parsing word with valid words array, if valid don't do anything
                if (substring == valid_words[j]){
                    is_valid = true;
                    break;
                }
            }
            if(is_valid == false){                               // if the parsing word is not valid, compare the word with incorrect words array
                bool is_incorrect = false;
                for(int k = 0; k < 10000; k++){
                    if (substring == incorrect_words[k]){
                        substring = correct_words[k];
                        is_incorrect = true;
                        break;
                    }
                }
                if(is_incorrect == false){                                   // if the parsing word is not in incorrect words array,
                    substring = start_marker + substring + end_marker;       // add start marker and end marker on the parsing word
                }
            }
            if(count == 0){                                                 // determine if the substring is the first word of the sentence
                new_line = substring;
            } else {
                new_line = new_line + " " +substring;
            }
            substring = "";                                                 // initialize the substring for storing next word
            count++;
        }
    }
    return new_line;
}

// the function read the input file and repair the lines, then output repaired lines into output file
void SpellChecker::repairFile(string input, string output){
    ifstream inStream(input,ios::in);
    ofstream outStream(output,ios::out);

    if(!inStream.is_open()){
        return;
    }

    string line;
    while(getline(inStream,line)){
        outStream << repair(line) << endl;
    }
    inStream.close();
    outStream.close();
    return;
}
