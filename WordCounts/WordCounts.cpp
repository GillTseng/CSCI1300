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
    string new_sentence = removePunLow(sentence);    //remove punctuation and make case lower
    string substring;
    for(int i = 0; i < new_sentence.length(); i++){
        if(new_sentence[i] != ' '){
            substring = substring + new_sentence[i];
        }
        if (new_sentence[i] ==' ' || i == new_sentence.length()-1){
                int dummy = -1;
                for (int j = 0; j < 10000 && words[j].length()>0; j++){
                    if (substring == words[j]){
                        word_count[j] = word_count[j] + 1;
                        dummy = j;
                        break;
                    }
                }
                if (dummy = -1){
                        for (int k = 0; k < 10000; k++){
                            if(words[k].length() == 0){
                                words[k] = substring;
                                word_count[k] = 1;
                                break;
                            }
                        }
                }
                substring ="";
        }
    }
    return;
}

int WordCounts::getTally(string wd){
    for(int i = 0; i < 10000; i++){
        if(words[i] == wd){
                return word_count[i];
        }
    }
}

void WordCounts::resetTally(){
    for(int i = 0; i < 10000 && words[i].length()>0; i++){
        word_count[i] = 0;
    }
    return;
}

int WordCounts::mostTimes(string most_words[],int most_counts[], int input_size){
    for (int i = 0; i < input_size; i++){
        int most_index = i;
        for(int j = i+1; j < 10000 && words[j].length()>0; j++){
            if (word_count[j] > most_index){
                most_index = j;
            }
        }

        if( most_index != i){
                string temp_word = words[i];
                int temp_count = word_count[i];
                words[i] = words[most_index];
                word_count[i] = word_count[most_index];
                words[most_index] = temp_word;
                word_count[most_index] = temp_count;
        }
        most_words[i] = words[i];
        most_counts[i] = word_count[i];
    }
    return 0;
}
