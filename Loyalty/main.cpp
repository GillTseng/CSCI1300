#include "Alumni.h"
#include "AlumniSystem.h"
#include <iostream>
#include <string>
using namespace std;

//22664,Christopher,Abuan,2007,Psychology
int main()
{
    AlumniSystem S1("../CUBBAYA_test.csv","../YA_Activities.txt","../YA_Rewards.txt");
    cout << "Welcome to Forever Buffs Reward Program" << endl
         << "- If you would like to login with your ID Number, please enter 1." << endl
         << "- If you you forget your ID Number, please enter 2." << endl
         << "- If you would like to join FBRP, please enter 3. " << endl;
    int num;
    cin >> num;
    if ( 1 == num){
        S1.findAlum(num);
        if (true == S1.findAlum(num)){
            cout << "Hello " << S1.getAlumni(S1.user_index).get_firstname() << "Your current point is: "
                 << S1.getAlumni(S1.user_index).get_point()<< endl;
        } else {
            cout << "Sorry, it seems like we don't have your information in the system.";
        }
    } else if ( 2 == num){
        string first;
        string last;
        int gy;
        string mj;
        cout << "Please enter your First Name";
    } else if ( 3 == num){

    } else {

    }

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
