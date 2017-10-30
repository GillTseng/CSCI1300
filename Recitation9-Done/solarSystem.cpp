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

string solarSystem::findLargest(){  // return the name of the largest planet
    int max_index = 0;
    for (int i = 0; i < numPlanets; i++){
        if ( planetDiameters[i] > planetDiameters[max_index]){
            max_index = i;
        }
    }
    return planetNames[max_index];
}

string solarSystem::getName(){      // return the name of the solar system
    return systemName;
}

float solarSystem::getDiameter(){   // return the diameter of the largest orbit
    int max_index = 0;
    for (int i = 0 ; i < numPlanets; i++){
        if ( planetOrbitDist[i] > planetOrbitDist[max_index]){
            max_index = i;
        }
    }
    return planetOrbitDist[max_index]*2;
}

int solarSystem::getNumPlanets(){         // return the number of planets in the system
    return numPlanets;
}

bool solarSystem::addPlanet(string name, float planetRadius, float planetDist){
    if(numPlanets < maxNumPlanets){
        planetNames[numPlanets] = name;
		planetDiameters[numPlanets] = 2*planetRadius;
		planetOrbitDist[numPlanets] = planetDist;
		numPlanets++;
		return numPlanets != 0;
    }
    return numPlanets==0;
}
