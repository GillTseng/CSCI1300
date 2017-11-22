#include "Alumni.h"
#include "AlumniSystem.h"
#include <iostream>
#include <string>
using namespace std;

//22664,Christopher,Abuan,2007,Psychology
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


    int event_select;
    int gift_select;
    int sum;
    string addr;
    string st;
    int zip_code;

    bool enter = false;
    do{
        S1.menuLines();
        cin >> opt;
        if (1 == opt){
            enter = true;
            cout << "Please choose below activities you would like to request points: " << endl << endl;
            for (int i = 0; i < 10 && S1.get_Events(i).length() > 0; i++){
                cout  << i << " - " << S1.get_Events(i) << '\t' << S1.get_EventPoints(i) << endl;
            }
            cin >> event_select;
            sum = S1.getAlumni(S1.user_index).get_point() + S1.get_EventPoints(event_select);
            S1.getAlumni(S1.user_index).set_point(sum);
            cout << "Thank you ! " << S1.getAlumni(S1.user_index).get_firstname() << ". Your request has been processed!" << endl
                 << "Your current point is: " << S1.getAlumni(S1.user_index).get_point() << endl;
        } else if ( 2 == opt){
            enter = true;
            cout << "Please choose below gifts you would like to redeem: " << endl << endl;
            for (int i = 0; i < 5 && S1.get_Gifts(i).length() > 0; i++){
                cout  << i << " - " << S1.get_Gifts(i) << '\t' << S1.get_GiftPoints(i) << endl;
            }
            cin >> gift_select;
            sum = S1.getAlumni(S1.user_index).get_point() - S1.get_GiftPoints(gift_select);
            S1.getAlumni(S1.user_index).set_point(sum);
            cout << "Thank you ! " << S1.getAlumni(S1.user_index).get_firstname() << ". Your request has been processed!" << endl
                 << "Your current point is: " << S1.getAlumni(S1.user_index).get_point() << endl;
            cout << "Please input your address, state and zip code: " << endl;
            cin >> addr >> st >> zip_code;
            S1.getAlumni(S1.user_index).set_address(addr);
            S1.getAlumni(S1.user_index).set_state(st);
            S1.getAlumni(S1.user_index).set_zip(zip_code);
        } else if ( 3 == opt){
            enter = true;
            S1.writeList("../YA List update.txt");
            return 0;
        } else {
            cout << "Sorry, we can't recognize your input. Please try again" << endl << endl;
        }
    } while (opt == false);
    return 0;
}
