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
//        void setDist(float);
//        float getDist();
//        float getOrbitPeriod();

    private:
        string name;
        float radius;
//        float distance;
};

#endif
