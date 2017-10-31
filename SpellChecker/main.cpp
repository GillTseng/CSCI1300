#include <iostream>
#include <string>
#include "SpellChecker.h"

using namespace std;

int main()
{
    SpellChecker test1("English","../VALID_WORDS_3000.txt","../Text2English.txt");
//    test1.setStartMarker('~');
//    test1.setEndMarker('~');
//    test1.repairFile("../miss_spell_test.txt","../miss_spell_complete.txt");
    return 0;
}
