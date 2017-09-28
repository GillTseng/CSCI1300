// Author: CS1300 Fall 2017 Enchieh Tseng
// Recitation: 110 – Monika Tak
// Recitation 5 Pattern

#include <iostream>
using namespace std;

/*
Example 1
-----------
rows = 6
*
* *
* * *
* * * *
* * * * *
* * * * * *

Example 2
-----------
rows = 4
*
* *
* * *
* * * *

Notice how many asterisks are on each line:
1 first row, 3 second row, 5 third row, ...
*/

int main ()
{
    int n_rows;
    cout << "Enter number of rows: ";
    cin >> n_rows;

    int last_len = n_rows*2-1;



    int row = 1;
    while (row <= n_rows)    // what is the condition needed to print correct # of rows?
    {
        // output the asterisks
        int n_asterisk = 1;
        while (n_asterisk <= row*2-1)  // what is the condition to print correct # of asterisks ?
	    {
            cout << "* ";
            // what is the modification to n_askerisk ?
            ++n_asterisk;
	    }
        cout << endl;
        ++row;
    }

  return 0;
}
