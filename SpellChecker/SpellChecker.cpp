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
    int pos = 0;
    while(getline(inStream,line)){
        if(line.length()>0){
                pos = line.find('\t');
                for (int i = 0; i < 10000; i++){
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
    //if first and last positions are punctuations, remove them
    for (int i = 0; i < pun.length(); i++){
        if(sent[0] == pun[i]){
            sent = sent.substr(1,sent.length()-1);
            break;
        }
    }
    for (int j = 0; j < pun.length(); j++){
        if(sent[sent.length()-1] == pun[j]){
            sent = sent.substr(0,sent.length()-1);
            break;
        }
    }

    for (int k = 0; k < sent.length(); k++){
        if (sent[k] >= 'A' && sent[k] <='Z'){
            sent[k] = (char)tolower(sent[k]);
        }
    }
    return sent;
}

string SpellChecker::repair(string sentence){
    string new_line;
    string substring;
    int count = 0;
    for (int i = 0; i < sentence.length(); i++){
        if(sentence[i] != ' '){
            substring = substring + sentence[i];
        }
        if (sentence[i] ==' ' || i == sentence.length()-1){
            bool is_valid = false;
            substring = removePunLow(substring);
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
            if(count == 0){
                new_line = substring;
            } else {
                new_line = new_line + " " +substring;
            }
            substring = "";
            count++;
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
