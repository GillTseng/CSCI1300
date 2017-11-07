#include "WordCounts.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    WordCounts test2;
    test2.tallyWords("today is a good day tomorrow is a bad day the day after tomorrow is a snow day");
    test2.getTally("day");
    string wd[3];
    int ct[3];
    test2.mostTimes(wd,ct,3);
    return 0;
}
