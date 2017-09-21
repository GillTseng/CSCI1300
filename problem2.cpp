// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 3
// Problem 2

# include <iostream>
# include <cmath>
using namespace std;


int windChillCalculator (double T, double V)
{
    double win_chill;
    win_chill = 35.74 + 0.6215 * T - 35.75 * pow(V,0.16) + 0.4275 * T * pow(V,0.16);
    return win_chill;
}

int main()
{
    cout.precision(4);
    cout << windChillCalculator(30.0,5.0);
}
