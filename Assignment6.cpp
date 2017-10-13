// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 6

# include <iostream>
# include <fstream>
using namespace std;

// Part 1.

float avgCharsPerLine (string filename){

    // calculate avg characters in each line (total character / number of lines)
    ifstream inStream (file, ios::in);

    if (inStream.fail())
    {
        return 0;
    }

    int num_line = 0;
    int char_count = 0;
    while (!inStream.eof())
    {

    }

}


// Part 2.

int fillArray (string filename, float array[][5]){

    // read the file and fill the array with file data (return number of lines in the file but exclude the header)
    ifstream inStream (filname ,ios::in);
    //input_stream.open(filname ,ios::in);

    if ( inStream.fail())
    {
        return 0;
    }

    int count =0;
    string line;
    while ( !inStream.eof())
    {
        getline(inStream, line);
        count++;
    }

    inStream.close();
    return count-1;

}
