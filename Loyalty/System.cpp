# include "Alumni.h"
# include "System.h"
# include <iostream>
# include <string>
# include <fstream>
using namespace std;

System::System(string filename){
	end_index = 0;
	//readList(filename);
}

System::~System(){

}

void System::readList(string filename){
	ifstream inStream(filename,ios::in);
	if(inStream.fail()){
		return;
	}

	string line;
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

Alumni System::getAlumni(int index){
    return YoungAlumni[index];
}

int System::findAlum(int input_id){
    for(int i = 0; i < max_cap; i++){
        if(getAlumni(i).get_ID() == input_id){
                user_index = i;
                return i;
        }
    }
    return -1;
}

int System::searchID(string first, string last, int gyr, string mj){
    bool name_match = false;
    int index;
    for(int i = 0; i < end_index; i++){
        if (first == getAlumni(i).get_firstname() && last == getAlumni(i).get_lastname()){
            name_match = true;
            index = i;
            break;
        }
    }
    if (name_match == true){
        if(gyr == getAlumni(index).get_gradyr() && mj == getAlumni(index).get_major()){
            user_index = index;
            return index;
        }
    }
    return -1;
}

int System::addAlumni(string first, string last, int gyr, string mj){
    YoungAlumni[end_index+1] = Alumni(getAlumni(end_index).get_ID()+1, first, last, gyr, mj);
    end_index++;
    user_index = end_index;
    return end_index;
}

int System::getRanking(){

}

void System::split(string line, char c, string arr[], int num){
    string substring = "";
    int count = 0;
    for (int i = 0; i < line.length(); i++){
        if(line[i] != c){
            substring = substring + line[i];
        }
        if (line[i] == c || i ==line.length()-1){
            arr[count] = substring;
            substring = "";
            count++;
        }
    }
    return;
}


void System::sortID(Alumni ya[]){
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
