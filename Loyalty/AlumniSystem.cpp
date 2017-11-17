# include "Alumni.h"
# include "AlumniSystem.h"
# include <iostream>
# include <string>
# include <fstream>
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

bool AlumniSystem::searchID(string first, string last, int gyr, string mj){
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

int AlumniSystem::getRanking(int id){
    sortPoint(YoungAlumni);
    for(int i = 0; i < end_index; i++){
        if(id == YoungAlumni[i].get_ID()){
            user_ranking = i+1;
        }
    }
    return user_ranking;
}

void AlumniSystem::requestPoint(int choice){
    int pnt = YoungAlumni[user_index].get_point()+events_points[choice];
    YoungAlumni[user_index].set_point(pnt);
    return;
}

void AlumniSystem::redeemPoint(int choice){
    if (gifts_points[choice] > YoungAlumni[user_index].get_point()){
        cout << "Sorry, you don't have enough points to redeem the gift. Please select other gift." <<endl;
        return;
    }
    int pnt = YoungAlumni[user_index].get_point() - gifts_points[choice];
    YoungAlumni[user_index].set_point(pnt);
    return;
}

void AlumniSystem::inputAddress(string add, string st, int zip_code){
    YoungAlumni[user_index].set_address(add);
    YoungAlumni[user_index].set_state(st);
    YoungAlumni[user_index].set_zip(zip_code);
    return;
}

bool AlumniSystem::writeList(string outfile){
    ofstream outStream(outfile, ios::out);
    if(outStream.fail()){
        return false;
    }
    outStream << "EID,First.Name,Last.Name,Grad.Year,Major.1,Address,State,Zip,Gift,Point" << endl;
    for(int i = 0; i < user_index; i++){
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
            if(count == num-1 && line[i+1] =='"'){
                arr[count] = line.substr(i+2,(line.length()-1)-(i+2));
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

void AlumniSystem::sortPoint(Alumni ya[]){
    for(int i = 0; i < end_index; i++){
        int max_index = i;
        for(int j = i +1; j < end_index; j++){
            if( ya[j].get_point() > ya[max_index].get_point()){
                max_index = j;
            }
        }
        Alumni temp = ya[i];
        ya[i] = ya[max_index];
        ya[max_index] = temp;
    }
    return;
}


Alumni AlumniSystem::getAlumni(int index){
    return YoungAlumni[index];
}
