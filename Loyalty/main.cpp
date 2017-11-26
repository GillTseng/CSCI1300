#include "Alumni.h"
#include "AlumniSystem.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    AlumniSystem S1("../CUBBAYA_test.csv","../YA_Activities.txt","../YA_Rewards.txt");
    int opt;
    bool login = false;
    do{
        S1.welcomeLines();
        cin >> opt;
        if (1 == opt){
            if(true ==S1.idLogin()){
            S1.showRaphie("../ralphie.txt", S1.getAlumni(S1.user_index).get_point());
            login = true;
            }
        } else if (2 == opt){
            if(true == S1.nameLogin()){
            S1.showRaphie("../ralphie.txt", S1.getAlumni(S1.user_index).get_point());
            login = true;
            }
        } else {
            S1.wrongmsgLines();
        }
    } while (login == false);           // if user can't successfully login then keep ask the question


    bool enter = false;
    do{
        S1.menuLines();
        cin >> opt;
        if (1 == opt){
            bool request = S1.requestPoint(S1.user_index);
            if(true == request){
                S1.showRaphie("../ralphie.txt", S1.getAlumni(S1.user_index).get_point());
                S1.updateLines();
                enter = true;
            } else if (false == request){
                enter = true;
            }
        } else if ( 2 == opt){
            bool redeem = S1.redeemPoint(S1.user_index);
            if(true == redeem){
                S1.showRaphie("../ralphie.txt", S1.getAlumni(S1.user_index).get_point());
                S1.updateLines();
                S1.enterAddress();
                enter = true;
            } else if (false == redeem){
                enter = true;
            }
        } else if ( 3 == opt ){
            S1.updateLines();
            S1.showRaphie("../ralphie.txt", S1.getAlumni(S1.user_index).get_point());
        } else if ( 4 == opt){
            S1.writeList("../YA List update.txt");
            return 0;
        } else {
            S1.wrongmsgLines();
            enter = true;
        }
    } while (enter == true);
    return 0;
}
