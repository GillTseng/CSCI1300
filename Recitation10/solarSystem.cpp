// Author: Enchieh Tseng
// Recitation: 110 – Monika Tak
//
// Recitation 10
// solarSystem .cpp file

#include "solarSystem.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

solarSystem::solarSystem(string name){
    systemName = name;
    numPlanets = 0;
}

solarSystem::~solarSystem(){
}

// return the name of the solar system
string solarSystem::getName(){
    return systemName;
}

// return the number of planets in the system
int solarSystem::getNumPlanets(){
    return numPlanets;
}

// add a single planet to solar system
bool solarSystem::addPlanet(string name, float radius){
    if(numPlanets < maxNumPlanets){                               // check if number of planets exceeded the capacity
            bool unique = true;                                   // create bool variable to indicate if the input planet is unique
            for (int i = 0; i < numPlanets; i++){                 // use for loop check existing planets in the system
                if (systemPlanets[i].getName() == name){
                    unique = false;                               // if the input planet has already existed make unique = false
                    return unique;
                }
            }
            if (unique = true){
                systemPlanets[numPlanets] = planet(name, radius);  // if the input planet is unique, then add it into the system
                numPlanets++;
            }
    } else {
        return false;
    }
    return true;
}

// return an object of planet at provided index
planet solarSystem::getPlanet(int index){
    return systemPlanets[index];
}

//calculate absolute radius difference between planets
float solarSystem::radiusDifference(planet p1, planet p2){
    return fabs(p1.getRadius() - p2.getRadius());
}
