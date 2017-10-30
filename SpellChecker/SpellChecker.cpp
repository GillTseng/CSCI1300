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

void SpellChecker::parsingSent(string sent){
    int pos = 0;
    int count = 0;
    for (int i = 0; i < sent.length(); i++){
        if(sent[i] ==' '){
                parsing_arr[count] = sent.substr(pos,i-pos);
                pos = i+1;
                count++;
        } else if (i == sent.length()-1){
            parsing_arr[count] = sent.substr(pos,sent.length()-pos);
        }
    }
    return;
}

string SpellChecker::repair(string sentence){
    string line = removePunLow(sentence);
    parsingSent(line);

    // compare with valid words and incorrect words
    for(int i = 0; i < 100; i++){
        if(parsing_arr[i].length()>0){
                bool is_valid = false;
                for(int j = 0; j < 10000; j++){                     //compare valid words, if valid don't do anything
                    if (parsing_arr[i] == valid_words[j]){
                        cout << parsing_arr[i] << endl;
                        is_valid = true;
                        break;
                    }
                }
                if(is_valid == false){                               // if is_valid = false, compare the word with incorrect words
                    bool is_incorrect = false;
                    for(int k = 0; k < 10000; k++){
                        if (parsing_arr[i] == incorrect_words[k]){
                            parsing_arr[i] = correct_words[k];
                            cout << correct_words[k] << endl;
                            is_incorrect = true;
                            break;
                        }
                    }
                    if(is_incorrect == false){
                        parsing_arr[i] = start_marker + parsing_arr[i] + end_marker;
                        cout << parsing_arr[i] << endl;
                    }
                }
        } else {
            break;
        }
    }

    string new_line;
    for(int i = 0; i < 100 && parsing_arr[i].length()>0; i++){
            if(0 == i){
                new_line = parsing_arr[i];
            } else {
                new_line = new_line + " " + parsing_arr[i];
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
