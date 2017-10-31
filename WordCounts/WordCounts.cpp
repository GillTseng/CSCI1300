#include "WordCounts.h"
#include <iostream>
#include <string>
using namespace std;

WordCounts::WordCounts(){

}

WordCounts::~WordCounts(){

}

string WordCounts::removePunLow(string sent){
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

void WordCounts::tallyWords(string sentence){
    string new_sentence = removePunLow(sentence);
    string substring;
    int count = 0;
    for(int i = 0; i < new_sentence.length(); i++){
        if(new_sentence[i] != ' '){
            substring = substring + new_sentence[i];
        }
        if (new_sentence[i] ==' ' || i == new_sentence.length()-1){

        }
    }
}
