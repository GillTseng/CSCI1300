# include "Alumni.h"
# include "System.h"
# include <iostream>
# include <string>
# include <fstream>
using namespace std;

System::System(string filename){
	readList(filename);
}

System::~System(){

}

System::readList(string filename){
	ifstream inStream(filenmae, ios::in);
	if(inStream.fail()){
		return;
	}

	string line;
	int count = 0;
	while(getline(inStream,line) && line.length() > 0 && count < max_cap){
		string temp[5];
		split(line,',',temp,5);
		getAlumni(count).set_ID(stoi(temp[0]));
		getAlumni(count).set_firstname(temp[1]);
		getAlumni(count).set_lastname(temp[2]);
		getAlumni(count).set_gradyr(stoi(temp[3]));
		getAlumni(count).set_major(temp[4]);
		count++;
	}
	inStream.close();
	end_index = count;
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
            return index
        }
    }
    return -1;
}

int System::addAlumni(string first, string last, int gyr, string mj){
    YoungAlumni[end_index+1] = Alumni(getAlumni(end_index).get_ID()+1, first, last, gyr, mg);
    end_index++;
    user_index = end_index;
    return end_index;
}


