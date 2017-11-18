#include "Alumni.h"
#include "AlumniSystem.h"
#include <iostream>
#include <string>
using namespace std;

//22664,Christopher,Abuan,2007,Psychology
int main()
{
    int opt;
    int num;
    string first;
    string last;
    int gy;
    string mj;

    AlumniSystem S1("../CUBBAYA_test.csv","../YA_Activities.txt","../YA_Rewards.txt");
    // Ask user's ID to retrieve user information (need to do cin getline)
    bool login = false;
    do{
        cout << "Welcome to Forever Buffs Reward Program" << endl
             << "- If you would like to login with your ID Number, please enter 1." << endl
             << "- If you you forget your ID Number, please enter 2." << endl;
        cin >> opt;
        if (1 == opt){
            cout << "Please enter your ID Number." << endl;
            cin >> num;
            if (true == S1.findAlum(num)){
                cout << "**************************************************" << endl
                     << "Hello " << S1.getAlumni(S1.user_index).get_firstname() << '!' << endl
                     << "Your ID Number is: " << S1.getAlumni(S1.user_index).get_ID() << endl
                     << "Your current point is: " << S1.getAlumni(S1.user_index).get_point()<< endl;
                     login = true;
            } else {
                cout << "Sorry, we don't have this ID number in the system. Please try again." << endl << endl;
            }
        } else if (2 == opt){
            cout << "Please enter your First Name, Last Name, Graduation Year and Major" << endl;
            cin >> first >> last >> gy >> mj;
            if(true == S1.searchAlum(first,last,gy,mj)){
                cout << "**************************************************" << endl
                     << "Hello " << S1.getAlumni(S1.user_index).get_firstname() << '!' << endl
                     << "Your ID Number is: " << S1.getAlumni(S1.user_index).get_ID() << endl
                     << "Your current point is: " << S1.getAlumni(S1.user_index).get_point()<< endl;
                     login = true;
            } else {
                if(true == S1.addAlumni(first,last,gy,mj)){
                    cout << "**************************************************" << endl
                         << "Hello " << S1.getAlumni(S1.user_index).get_firstname() << '!' << endl
                         << "Your ID Number is: " << S1.getAlumni(S1.user_index).get_ID() << endl
                         << "Your current point is: " << S1.getAlumni(S1.user_index).get_point()<< endl;
                         login = true;
                } else {
                    cout << "Sorry, we can't recognize your input. Please try again" << endl << endl;
                }
            }
        } else {
            cout << "Sorry, we can't recognize your input. Please try again" << endl << endl;
        }

    } while (login == false);

    cout << "**************************************************" << endl << endl;
    bool enter = false;
    int event_select;
    int gift_select;
    int sum;
    do{
        cout << "Please select following options: " << endl
             << "1 - Request your point" << endl
             << "2 - Redeem your point" << endl
             << "3 - Log out" << endl;
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
            cout << S1.getAlumni(S1.user_index).get_point() <<endl;
            cout << "Thank you ! " << S1.getAlumni(S1.user_index).get_firstname() << ". Your request has been processed!" << endl
                 << "Your current point is: " << S1.getAlumni(S1.user_index).get_point() << endl;
        } else if ( 2 == opt){
            enter = true;

        } else if ( 3 == opt){
            enter = true;
            S1.writeList("../YA List update.txt");
            return 0;
        } else {

        }
    } while (opt == false);
    return 0;
}
