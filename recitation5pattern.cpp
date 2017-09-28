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
    while (row <= n_rows) // start with the first row
    {
        int i = 0;
        while ( i < n_rows - row) //find and print out spaces before *
        {
            cout << "  ";
            i++;
        }
        while ( i < last_len-n_rows+row) // print out *(s) in the row
        {
            cout << "* ";
            i++;
        }
        row++; // move to the next row
        cout << endl;
    }
  return 0;
}
