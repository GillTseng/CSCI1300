// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 7
// Part 2

#include "WordCounts.h"
#include <iostream>
#include <string>
using namespace std;

WordCounts::WordCounts(){

}

WordCounts::~WordCounts(){

}

// the function is a helper function to remove punctuations and then turn upper case to lower case
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
        } else if (is_pun == false && sent[i] >= 'A' && sent[i] <='Z'){
            line = line + (char)tolower(sent[i]);
        }
    }
    return line;
}

// the function read sentence and count frequency of each word in the sentence
void WordCounts::tallyWords(string sentence){
    string new_sentence = removePunLow(sentence);       //remove punctuations and make upper case to lower case
    string substring;
    for(int i = 0; i < new_sentence.length(); i++){
        if(new_sentence[i] != ' '){                     // if the new_sentence[i] is not space then append the sentence[i] to substring
            substring = substring + new_sentence[i];
        }
        if (new_sentence[i] ==' ' || i == new_sentence.length()-1){         //if new_sentence[i] is space then process the parsing word
                int dummy = -1;                                             //create a dummy int to indicate if the word already existed
                for (int j = 0; j < 10000 && words[j].length()>0; j++){     //check if the parsing word is already existed
                    if (substring == words[j]){                             //in the words array, if existed word_count+1
                        word_count[j] = word_count[j] + 1;
                        dummy = j;                                          //if the word already existed then dummy int = word's position
                        break;
                    }
                }
                if (dummy == -1){                                            //if parsing word does not exist in the array
                        for (int k = 0; k < 10000; k++){                    //find next vacant index and store the word into words array
                            if(words[k].length() == 0){                     //and count 1 into word_count array
                                words[k] = substring;
                                word_count[k] = 1;
                                break;
                            }
                        }
                }
                substring ="";                                              // initialize the substring for storing next word
        }
    }
    return;
}

// the function return count of the input word
int WordCounts::getTally(string wd){
    for(int i = 0; i < 10000; i++){
        if(words[i] == wd){
                return word_count[i];
        }
    }
}

// the function reset all word count to 0
void WordCounts::resetTally(){
    for(int i = 0; i < 10000 && words[i].length()>0; i++){
        word_count[i] = 0;
    }
    return;
}

// the function fill top n most frequent words into a string array and their frequency into an integer array
// use selection sorting the input the arrays
int WordCounts::mostTimes(string most_words[],int most_counts[], int input_size){
    for (int i = 0; i < input_size; i++){                           //since we only need top n most frequent words, only need to run n times
        int most_index = i;
        for(int j = i+1; j < 10000 && words[j].length()>0; j++){    //find most frequent word
            if (word_count[j] > word_count[most_index]){
                most_index = j;
            }
        }

        if( most_index != i){                                       //swap the most frequent word's position with position[i]
                string temp_word = words[i];
                int temp_count = word_count[i];
                words[i] = words[most_index];
                word_count[i] = word_count[most_index];
                words[most_index] = temp_word;
                word_count[most_index] = temp_count;
        }
        most_words[i] = words[i];                                   //fill in arrays
        most_counts[i] = word_count[i];
    }
    return 0;
}
