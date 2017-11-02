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

string solarSystem::getName(){      // return the name of the solar system
    return systemName;
}

int solarSystem::getNumPlanets(){         // return the number of planets in the system
    return numPlanets;
}

bool solarSystem::addPlanet(string name, float radius){           //Adds a single planet to solar system
    if(numPlanets < maxNumPlanets){
            bool unique = true;
            for (int i = 0; i < numPlanets; i++){
                if (systemPlanets[i].getName() == name){
                    unique = false;
                    return unique;
                }
            }
            if (unique = true){
                systemPlanets[numPlanets] = planet(name, radius);
                numPlanets++;
            }
    } else {
        return false;
    }
    return true;
}

planet solarSystem::getPlanet(int index){           // return an object of planet at provided index
    return systemPlanets[index];
}

float solarSystem::radiusDifference(planet p1, planet p2){
    return fabs(p1.getRadius() - p2.getRadius());
}
