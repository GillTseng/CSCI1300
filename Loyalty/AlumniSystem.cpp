# include "Alumni.h"
# include "AlumniSystem.h"
# include <iostream>
# include <string>
# include <fstream>
using namespace std;

AlumniSystem::AlumniSystem(){
}

AlumniSystem::AlumniSystem(string filename){
	end_index = 0;
	readList(filename);
}

AlumniSystem::~AlumniSystem(){

}

void AlumniSystem::readList(string filename){
	ifstream inStream(filename,ios::in);
	if(inStream.fail()){
		return;
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
	return;
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

int AlumniSystem::getRanking(){

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

Alumni AlumniSystem::getAlumni(int index){
    return YoungAlumni[index];
}
