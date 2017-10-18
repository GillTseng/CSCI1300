// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 6

# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>
using namespace std;

// Part 1.

float avgCharsPerLine (string filename){

    // calculate avg characters in each line (total character / number of lines)
    ifstream inStream (filename, ios::in);  //same with ifstream inStream;  inStream.open(filename);

    if (inStream.fail())
    {
        return 0;
    }

    float num_line = 0;
    float num_char = 0;
    string line;

    while (!inStream.eof())
    {
        getline (inStream, line);
        num_line++;
        num_char= num_char + line.length();
    }

    inStream.close();
    return num_char / num_line;
}


// Part 2.

int fillArray (string filename, float array[][5]){

    // read the file and fill the array with file data (return number of lines in the file but exclude the header)
    ifstream inStream (filename ,ios::in);

    if ( inStream.fail())
    {
        return 0;
    }

    int count =0;
    string line;
    getline(inStream,line);

    while ( !inStream.eof())
    {
        getline(inStream, line);

        string temp_num ="";
        int j =0;
        for (int i = 0; i < line.length(); i++)
        {
            if ( line[i] !=',' && line[i] != ' ')
            {
                temp_num = temp_num + line[i];
            }
            if ( line[i] == ',' | i == line.length()-1)
            {
                array [count][j]= stof(temp_num);
                j++;
                temp_num ="";
            }
        }
        count++;
    }

    inStream.close();
    return count;

}


// Part 3.

float arrayStats (string filename, float numbers[][5]){

    int num_row = fillArray(filename, numbers);

    float arr_mean[num_row];
    int i = 0;
    float temp_sum = 0;

    for ( int col = 1; col < 5; col=col+2){
        for ( int row = 0; row < num_row; row++){
            temp_sum = temp_sum + numbers[row][col];
        }
        arr_mean[i] = temp_sum / num_row;
        temp_sum = 0;
        i++;
    }

    for ( int row = 1; row < num_row; row=row+2){
        for ( int col = 0; col < 5; col++){
            temp_sum = temp_sum + numbers[row][col];
        }
        arr_mean[i] = temp_sum / 5;
        temp_sum = 0;
        i++;
    }

    float sum = 0;
    for (int j = 0; j < i; j++){
        sum = sum + arr_mean[j];
    }
    return sum;
}



// Part 4.
void addBookRatings (string filename, string users[], int ratings[][50]){

    int max_row = 100;
    for (int row = 0; row < max_row; row++){
        for (int col=0; col < 50; col++){
           ratings[row][col] = 0;
        }
    }

    ifstream inStream (filename, ios::in);
    if (inStream.fail())
    {
        return;
    }

    string line;
    getline(inStream,line);

    int count = 0;
    while (!inStream.eof()){
        getline(inStream,line);
        count ++;

        string temp_arr[3];         // create a string array to store 3 parsing strings
        string temp="";
        int j=0;
        for (int i = 0; i < line.length(); i++){
            if (line[i] !=','){
                temp = temp + line[i];
            }
            if (line[i] ==',' | i == line.length()-1){
                temp_arr[j] = temp;
                //cout << temp_arr[j] << endl;
                j++;
                temp="";
            }
        }


        int dummy_num = -1;
        for (int k = 0; k < count; k++){            // check if the user name already exist in the array
            if (users[k] == temp_arr[0]){

                int book_index = stoi(temp_arr[1]);
                int score = stoi(temp_arr[2]);
                if (ratings[k][book_index] == 0){
                    ratings[k][book_index] = score;
                }
                dummy_num = k;
            }
//            cout << k << ": " << users[k] << endl;
//            cout << temp_arr[0] << endl;
//            cout << dummy_num << endl;
//            cout <<"----------------"<< endl;
        }

        if ( dummy_num == -1){
            for (int k = 0; k < count; k++){
                if (users[k].length() == 0){
                    users[k] = temp_arr[0];

                    int book_index = stoi(temp_arr[1]);
                    int score = stoi(temp_arr[2]);
                    ratings[k][book_index] = score;
                    break;
                }
            }
        }


    }
//    for (int i = 0; i < count; i++){
//        cout<< users[i] << endl;
//    }
}
