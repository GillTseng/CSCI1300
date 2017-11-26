# include "Alumni.h"
# include "AlumniSystem.h"
# include <iostream>
# include <string>
# include <fstream>

# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define RESET   "\033[0m"

using namespace std;

AlumniSystem::AlumniSystem(){
}

AlumniSystem::AlumniSystem(string alumnilist, string eventlist, string giftlist){
	end_index = 0;
	readList(alumnilist);
    readEventList(eventlist);
    readGiftList(giftlist);
}

AlumniSystem::~AlumniSystem(){

}

bool AlumniSystem::readList(string filename){
	ifstream inStream(filename,ios::in);
	if(inStream.fail()){
		return false;
	}

	string line;
	getline(inStream,line);
	while(getline(inStream,line) && line.length() > 0 && end_index < max_cap){
		string temp[5];
		split(line,',',temp,5);
		YoungAlumni[end_index] = Alumni(stoi(temp[0]),temp[1],temp[2],stoi(temp[3]),temp[4]);
		end_index++;
	}

	sortID(YoungAlumni);
	inStream.close();
	return true;
}

bool AlumniSystem::readEventList(string filename){
    ifstream inStream(filename, ios::in);
    if(inStream.fail()){
        return false;
    }
    string line;
    getline(inStream,line);
    int count = 0;
    while(getline(inStream,line) && line.length()>0){
        string temp[2];
        split(line,',',temp,2);
        events[count] = temp[0];
        events_points[count] = stoi(temp[1]);
        count++;
    }
    inStream.close();
    return true;
}

bool AlumniSystem::readGiftList(string filename){
    ifstream inStream(filename,ios::in);
    if(inStream.fail()){
        return false;
    }
    string line;
    getline(inStream,line);
    int count = 0;
    while(getline(inStream,line) && line.length() > 0){
        string temp[2];
        split(line,',',temp,2);
        gifts[count] = temp[0];
        gifts_points[count] = stoi(temp[1]);
        count++;
    }
    inStream.close();
    return true;
}

bool AlumniSystem::findAlum(int input_id){
    for(int i = 0; i < max_cap; i++){
        if(input_id == getAlumni(i).get_ID()){
                user_index = i;
                return true;
        }
    }
    return false;
}

bool AlumniSystem::searchAlum(string first, string last, int gyr, string mj){
    for(int i = 0; i < end_index; i++){
        if (last == YoungAlumni[i].get_lastname() &&
            first == YoungAlumni[i].get_firstname() &&
            gyr == YoungAlumni[i].get_gradyr() &&
            mj == YoungAlumni[i].get_major()){
                user_index = i;
                break;
                return true;
            }
    }
    return false;
}

bool AlumniSystem::addAlumni(string first, string last, int gyr, string mj){
    if (end_index < max_cap){
        YoungAlumni[end_index] = Alumni(getAlumni(end_index-1).get_ID()+1, first, last, gyr, mj);
        user_index = end_index;
        end_index++;
        return true;
    }
    return false;
}

void AlumniSystem::showRaphie(string filename, int user_point){
    ifstream inStream(filename, ios::in);
    if(inStream.fail()){
        return;
    }
    string line;
    int count = 1;
    while(getline(inStream, line)){
        // star color will change according to user's point
        for (int i = 0; i < line.length(); i++){
            if (line[i] == '0' || line[i] == ','){
                cout << " ";
            } else if (line[i] == '1' && count <= user_point ){
                cout << BOLDYELLOW << "*" << RESET;
                count++;
            } else if (line[i] == '1' && count > user_point){
                cout << "*";
            }
        }
        cout << endl;
    }
    inStream.close();
    return;
}

string AlumniSystem::get_Events(int index){
    return events[index];
}

int AlumniSystem::get_EventPoints(int index){
    return events_points[index];
}

string AlumniSystem::get_Gifts(int index){
    return gifts[index];
}

int AlumniSystem::get_GiftPoints(int index){
    return gifts_points[index];
}

bool AlumniSystem::writeList(string outfile){
    ofstream outStream(outfile, ios::out);
    if(outStream.fail()){
        return false;
    }
    outStream << "EID,First.Name,Last.Name,Grad.Year,Major.1,Address,State,Zip,Gift,Point" << endl;
    for(int i = 0; i <= user_index; i++){
        outStream << YoungAlumni[i].get_ID() << ',' << YoungAlumni[i].get_firstname() << ',' <<
                     YoungAlumni[i].get_lastname() << ',' << YoungAlumni[i].get_gradyr() << ',' <<
                     YoungAlumni[i].get_major() << ',' << YoungAlumni[i].get_address() << ',' <<
                     YoungAlumni[i].get_state() << ',' << YoungAlumni[i].get_zip() << ',' <<
                     YoungAlumni[i].get_gift() << ',' << YoungAlumni[i].get_point() << endl;
    }
    outStream.close();
    return true;
}

void AlumniSystem::split(string line, char c, string arr[], int num){
    string substring = "";
    int count = 0;
    for (int i = 0; i < line.length(); i++){
        if(line[i] != c){
            substring = substring + line[i];
        }
        if (line[i] == c){
            arr[count] = substring;
            substring = "";
            count++;
            if(count == num-1 && line[i+1] =='"'){                          // to remove double quote that in the last parsing string,
                arr[count] = line.substr(i+2,(line.length()-1)-(i+2));      // which contain ',' in it.
                break;
            } else if(count == num-1 && line[i+1] !='"'){
                arr[count] = line.substr(i+1,line.length()-(i+1));
                break;
            }
        }

    }
    return;
}

void AlumniSystem::sortID(Alumni ya[]){
    for(int i = 0; i < end_index; i++){
        int min_index = i;
        for (int j = i+1; j < end_index; j++){
            if(ya[min_index].get_ID() > ya[j].get_ID()){
                min_index = j;
            }
        }
        Alumni temp = ya[i];
        ya[i] = ya[min_index];
        ya[min_index] = temp;
    }
    return;
}

Alumni AlumniSystem::getAlumni(int index){
    return YoungAlumni[index];
}

void AlumniSystem::welcomeLines(){
    cout << "Welcome to Forever Buffs Reward Program!" << endl
         << "Please choose below method to log in:" << endl
         << "1 - I would like to login with my ID Number" << endl
         << "2 - I forgot my ID Number / I don't have ID Number"  << endl;
    return;
}

bool AlumniSystem::idLogin(){
    int num;
    cout << endl << "Please enter your ID Number." << endl;
    cin >> num;
    if (true == findAlum(num)){
            loginLines();
            return true;
    } else {
        wrongmsgLines();
        return false;
    }
    return false;
}

bool AlumniSystem::nameLogin(){
    string first;
    string last;
    int gy;
    string mj;

    cin.ignore();
    cout << endl << "Please enter your First Name: " << endl;
    getline(std::cin,first);
    cout << "Please enter your Last Name: " << endl;
    getline(cin,last);
    cout << "Please enter your Major: " << endl;
    getline(cin,mj);
    cout << "Please enter your Graduation Year: " << endl;
    cin >> gy;

    if(true == searchAlum(first,last,gy,mj)){           // if can't search user's information then add the user into system
            loginLines();
            return true;
    } else {
        if(true == addAlumni(first,last,gy,mj)){
            loginLines();
            return true;
        } else {
            wrongmsgLines();
            return false;
        }
    }
    return false;
}

void AlumniSystem::loginLines(){
    cout << endl
         << "*********************************************************************" << endl
         << "Hello " << getAlumni(user_index).get_firstname() << '!' << endl
         << "Your ID Number is: " << getAlumni(user_index).get_ID() << endl
         << "Your current point is: " << getAlumni(user_index).get_point()<< endl
         << "*********************************************************************" << endl << endl;
    return;
}

void AlumniSystem::wrongmsgLines(){
    cout << endl << "Sorry, we can't recognize your input. Please try again" << endl << endl;
}

void AlumniSystem::menuLines(){
    cout << "Please select following options: " << endl
         << "1 - Request your point" << endl
         << "2 - Redeem your point" << endl
         << "3 - Check my Status" << endl
         << "4 - Log out" << endl;
    return;
}

bool AlumniSystem::requestPoint(int index){
    int event_select;
    int sum;
    do {
        cout << endl << "Please choose below activities you would like to request points: " << endl;
        for (int i = 0; i < 10 && get_Events(i).length() > 0; i++){
            cout  << i << " - " << get_Events(i) << '\t' << get_EventPoints(i) << endl;
        }
        cout << "-1" << " - " << "Back to last page." << endl;
        cin >> event_select;
        if (event_select >= 0 && event_select <= 6){
            sum = YoungAlumni[index].get_point() + get_EventPoints(event_select);
            YoungAlumni[index].set_point(sum);
            return true;
        } else if ( -1 == event_select){
            return false;
        } else {
            wrongmsgLines();
        }
    } while ( event_select < -1 || event_select > 6);        // if user's input can't be recognized then keep asking the question
    return false;
}

bool AlumniSystem::redeemPoint(int index){
    int gift_select;
    int sum;
    cout << endl << "Please choose below gifts you would like to redeem: " << endl;
    do {
        for (int i = 0; i < 5 && get_Gifts(i).length() > 0; i++){
            cout  << i << " - " << get_Gifts(i) << '\t' << get_GiftPoints(i) << endl;
        }
        cout << "-1" << " - " << "Back to last page." << endl;
        cin >> gift_select;
        if (gift_select >= 0 && gift_select <= 4 && YoungAlumni[index].get_point() >= get_GiftPoints(gift_select)){
                sum = YoungAlumni[index].get_point() - get_GiftPoints(gift_select);
                YoungAlumni[index].set_point(sum);
                YoungAlumni[index].set_gift(get_Gifts(gift_select));
                return true;
        } else if (YoungAlumni[index].get_point() < get_GiftPoints(gift_select)){
            cout << "Sorry, you don't have enough points to redeem this gift." << endl << endl
                 << "Please choose other gift to redeem." << endl;
        } else if ( -1 == gift_select){
            return false;
        } else {
            wrongmsgLines();
        }
    // if user's input can't be recognized or user's point is not enough to redeem then keep asking the question
    } while (YoungAlumni[index].get_point() < get_GiftPoints(gift_select) || gift_select < -1 || gift_select > 4);
    return false;
}

void AlumniSystem::updateLines(){
    cout << endl <<  "Thank you! " << getAlumni(user_index).get_firstname() << endl
         << "Your current point is: " << getAlumni(user_index).get_point() << endl << endl;
}

void AlumniSystem::enterAddress(){
    string addr;
    string st;
    int zip_code;

    cin.ignore();
    cout << "Please input your address: " << endl;
    getline(cin,addr);
    cout << "Please input your state: " << endl;
    getline(cin,st);
    cout << "Please input your zip code: " << endl;
    cin >> zip_code;

    getAlumni(user_index).set_address(addr);
    getAlumni(user_index).set_state(st);
    getAlumni(user_index).set_zip(zip_code);
    cout << endl << "Thank you, " << YoungAlumni[user_index].get_firstname() << ". Your request has been received !" << endl
         << "We will ship your gift to above address in 3-5 business days." << endl << endl;
    return;
}
