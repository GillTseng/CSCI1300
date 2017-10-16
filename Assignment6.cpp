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

}


int main()
{
    float arr [3][5];
    fillArray("test.txt", arr);
    return 0;
}
