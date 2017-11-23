#include "Alumni.h"
#include "AlumniSystem.h"
#include <iostream>
#include <string>
using namespace std;

//22664,Christopher,Abuan,2007,Psychology
// add new 554692
int main()
{
    int opt;
    AlumniSystem S1("../CUBBAYA_test.csv","../YA_Activities.txt","../YA_Rewards.txt");
    bool login = false;
    do{
        S1.welcomeLines();
        cin >> opt;
        if (1 == opt){
            if(true ==S1.idLogin()){
            login = true;
            }
        } else if (2 == opt){
            if(true == S1.nameLogin()){
            login = true;
            }
        } else {
            S1.wrongmsgLines();
        }
    } while (login == false);


    bool enter = false;
    do{
        S1.menuLines();
        cin >> opt;
        if (1 == opt){
            if(true == S1.requestPoint(S1.user_index)){
                S1.updateLines();
                enter = true;
            } else if (false == S1.requestPoint(S1.user_index)){
                enter = true;
            }
        } else if ( 2 == opt){
            if(true == S1.redeemPoint(S1.user_index)){
                S1.updateLines();
                S1.enterAddress();
                enter = true;
            } else if (false == S1.redeemPoint(S1.user_index)){
                enter = true;
            }
        } else if ( 3 == opt){
            S1.writeList("../YA List update.txt");
            return 0;
        } else {
            S1.wrongmsgLines();
            enter = true;
        }
    } while (enter == true);
    return 0;
}
