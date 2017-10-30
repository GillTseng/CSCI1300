#include <iostream>
#include <string>
#include "SpellChecker.h"

using namespace std;

int main()
{
    SpellChecker test1;
    test1.readValidWords("../VALID_WORDS_3000.txt");
}
