// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Recitation 10
// planet header file

#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <string>
using namespace std;

class planet{
    public:
        planet();
        planet(string, float);
        ~planet();
        void setName(string);
        string getName();
        void setRadius(float);
        float getRadius();

    private:
        string name;
        float radius;
};

#endif
