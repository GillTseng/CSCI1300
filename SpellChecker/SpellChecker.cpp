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

bool SpellChecker::readValidWords(string validfile){
    ifstream inStream (validfile, ios::in);
    if (!inStream.is_open()){
        return inStream.is_open();
    }

    string line;
    int count = 0;
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
        return inStream.is_open();
    }

    string line;
    int count = 0;
    int pos = 0;
    while(getline(inStream,line)){
        if(line.length()>0){
                pos = line.find('\t');
                incorrect_words[count] = line.substr(0,pos);
                correct_words[count] = line.substr(pos+1,line.length()-(pos+1));
                count++;
        }
    }
    inStream.close();
    return pos != 0;
}

bool SpellChecker::setStartMarker(char startmkr){
    start_marker = startmkr;
    return start_marker == startmkr;
}

bool SpellChecker::setEndMarker(char endmkr){
    end_marker = endmkr;
    return end_marker == endmkr;
}

char SpellChecker::getStartMarker(){
    return start_marker;
}

char SpellChecker::getEndMarker(){
    return end_marker;
}

string SpellChecker::removePunLow(string sent){
    string line;
    for (int i = 0; i < sent.length(); i++){
        bool is_pun = false;
        for (int j = 0; j < pun.length(); j++){
            if(sent[i] == pun[j]){
                is_pun = true;
                break;
            }
        }
        if (is_pun == false && (sent[i] < 'A' || sent[i] > 'Z')){
            line = line + sent[i];

        } if (is_pun == false && sent[i] >= 'A' && sent[i] <='Z'){
            line = line + (char)tolower(sent[i]);
        }
    }
    return line;
}

string SpellChecker::repair(string sentence){
    string line = removePunLow(sentence);
    string new_line;
    string substring;
    for (int i = 0; i < line.length(); i++){
        if(line[i] != ' '){
            substring = substring + line[i];
        }
        if (line[i] ==' ' || i == line.length()-1){
            bool is_valid = false;
            for(int j = 0; j < 10000; j++){                     //compare valid words, if valid don't do anything
                if (substring == valid_words[j]){
                    is_valid = true;
                    break;
                }
            }
            if(is_valid == false){                               // if is_valid = false, compare the word with incorrect words
                bool is_incorrect = false;
                for(int k = 0; k < 10000; k++){
                    if (substring == incorrect_words[k]){
                        substring = correct_words[k];
                        is_incorrect = true;
                        break;
                    }
                }
                if(is_incorrect == false){
                    substring = start_marker + substring + end_marker;
                }
            }
            if(i != line.length()-1){
                new_line = new_line + substring + " ";
            } else {
                new_line = new_line + substring;
            }
            substring = "";
        }
    }
    return new_line;
}

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
