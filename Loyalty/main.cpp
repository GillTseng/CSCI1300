#include "Alumni.h"
#include "AlumniSystem.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{

    AlumniSystem S1("../CUBBAYA_test.csv","../YA_Activities.txt","../YA_Rewards.txt");
    S1.getRanking(S1.getAlumni(0).get_ID());

//    string first = "Gill";
//    string last = "Tseng";
//    int gy = 2015;
//    string mj = "Business Analytics";
//    S1.searchID(first, last, gy, mj);
//    if(false == S1.searchID(first, last, gy, mj)){
//        S1.addAlumni(first, last, gy, mj);
//    }
//    cout << S1.getAlumni(S1.user_index).get_ID() << '\t' << S1.getAlumni(S1.user_index).get_firstname();

    return 0;
}
