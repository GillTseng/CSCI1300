// Author: CS1300 Fall 2017 Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Assignment 2

#include <iostream>

using namespace std;

/**
 * The function is for calculating U.S. population in one year
 * base on birth rate, death rate and immigration rate.
 */
int howMany(int population) {
    int sec_per_year = 365*24*60*60;
    float birth_rate =1.0/8.0;
    float death_rate =1.0/12.0;
    float immigration_rate =1.0/33.0;
    int population_oneyear;
    population_oneyear = population+sec_per_year*(birth_rate+immigration_rate-death_rate);
    return population_oneyear;
}


/**
 * Given a number of seconds in range of 0-1,000,000
 * calculate the number equals to how many days, hours, minutes and seconds.
 */
void howLong(int seconds) {
    if (seconds >= 0 && seconds <= 1000000){
        int W;
        int X;
        int Y;
        int Z;
        int day = 24*60*60;
        int hour = 60*60;
        int minute = 60;
        W = seconds/day;
        X = (seconds-W*day) / hour;
        Y = (seconds-W*day-X*hour) / minute;
        Z = seconds-W*day-X*hour-Y*minute;
        cout << "Time is " <<W<< " days, " <<X<< " hours, " <<Y<< " minutes, and "<<Z<< " seconds." <<endl;
        return;
    }
    else{
        cout << "Time is 0 days, 0 hours, 0 minutes, and 0 seconds." <<endl;
        return;
    }
}


/**
 * The function is for converting Celsius temperature into Fahrenheit
 */
int howHot(int temperature) {
    if (temperature >= -17 && temperature <=36 ){
        float fahrenheit;
        int fahrenheit_int;
        fahrenheit = temperature * 9.0/5 +32;
        fahrenheit_int = fahrenheit+0.5;
        return fahrenheit_int;
    }
    else if (temperature >36){
        int fahrenheit_int;
        fahrenheit_int = temperature * 9.0/5 +32;
        return fahrenheit_int;
    }
    else {
        float fahrenheit;
        int fahrenheit_int;
        fahrenheit = temperature * 9.0/5 +32;
        fahrenheit_int = fahrenheit-0.5;
        return fahrenheit_int;
    }

}


int main() {
    // Problem 1 test
    // Change value of 'pop' to change value you want to test
    int pop = 1000000;
    cout << "Given the initial population of " << pop;
    cout << " your estimation finds a population of ";
    cout << howMany(pop) << endl << endl;

    // Problem 2 test
    // Change value 'sec' to change value you want to test
    int sec = -1;
    cout << "Given the seconds value of " << sec;
    cout << " your output is: " << endl;
    howLong(sec);
    cout << endl;

    // Problem 3 test
    // Change value 'temp' to change value you want to test
    int temp = 37;
    cout << "Given temperature " << temp;
    cout << " degrees Celsius you calculate ";
    cout << howHot(temp) << " degrees Fahrenheit" << endl;
    return 0;
}
