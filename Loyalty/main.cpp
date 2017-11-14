#include "Alumni.h"
#include "AlumniSystem.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
//    AlumniSystem S1;
    AlumniSystem S1("../CUBBAYA_test.csv");
//    S1.findAlum(554316);
    S1.searchID("Lisa", "Batter", 2005, "Humanities"); //663
//    cout << S1.getAlumni(0).get_major().length() << endl;

//    Alumni A1;
    return 0;
}
