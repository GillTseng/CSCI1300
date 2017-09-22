// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 3
// Problem 2

# include <iostream>
# include <cmath>
using namespace std;


/**
* Algorithm description:
* Calculate wind chill when given air temperature in Fahrenheit(T) and wind speed(V).
* Wind chill = 35.74 + 0.6215 * T - 35.75 * V^0.16 + 0.4275 * T * V^0.16)
* Return wind chill.
*/

float windChillCalculator (float T, float V)
{
    float win_chill;
    win_chill = 35.74 + 0.6215 * T - 35.75 * pow(V,0.16) + 0.4275 * T * pow(V,0.16);
    return win_chill;
}


/**
* Algorithm description:
* When given air temperature in Fahrenheit and range of wind speed, print wind chill that increment by wind speed step.
*/
void printWindChill (float T, float low_wind_speed, float high_wind_speed, float wind_speed_step)
{
    float V = low_wind_speed;
    while (V >= low_wind_speed && V <= high_wind_speed)
    {
        cout << "The wind chill is " << windChillCalculator(T,V) << " degrees F for an air temperature of " << T <<
        " degrees F" << " and a wind speed of " << V << " mph." << endl;
        V = V + wind_speed_step;

    }
}

int main()
{
    printWindChill(30.0,5.0,8.0,1.0);
}
