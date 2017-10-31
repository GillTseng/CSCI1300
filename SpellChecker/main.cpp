#include <iostream>
#include <string>
#include "SpellChecker.h"

using namespace std;

int main()
{
//    SpellChecker test1("English","../VALID_WORDS_3000.txt","../MISSPELLED.txt");
    SpellChecker test1("English");
    test1.readCorrectedWords("../MISSPELLED.txt");
    test1.readCorrectedWords("../Text2English.txt");
//    test1.setStartMarker('~');
//    test1.setEndMarker('~');
//    test1.repairFile("../miss_spell_test.txt","../miss_spell_complete.txt");
    return 0;
}
