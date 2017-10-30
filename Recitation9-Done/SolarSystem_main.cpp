#include <iostream>
#include "planet.h"
#include "planet.cpp"
#include "solarSystem.h"
#include "solarSystem.cpp"

// TODO: Include the header files for the planet class (part 2) and the solar system class (part 3)

using namespace std;

int main(){

	/// Part 2: Planets

	//TODO: Declare 4 instances of the planet class, using the following table for reference
    string pnt[4] = {"Mercury","Venus","Earth","Mars"};
    float rad[4] = {2440,6052,6371,3390};
    float dis[4] = {0.387,0.723,1.000,1.524};
    planet p[4];
    for (int i = 0; i < 4; i++){
        p[i].setName(pnt[i]);
        p[i].setRadius(rad[i]);
        p[i].setDist(dis[i]);
    }
	/*  NAME	RADIUS (km)		ORBIT RADIUS (AU)
	Mercury		2440     		0.387
	Venus     	6052       		0.723
	Earth     	6371       		1.000
	Mars      	3390     		1.524
	*/

	// Use the following print statements to test your planet class code
	for(int i = 0; i < 4; i++)
	{
		cout << "The orbit of " << p[i].getName();
		cout << " takes " << p[i].getOrbitPeriod() << " years." << endl;
		cout << "The diameter of " << p[i].getName();
		cout << " is " << p[i].getDiameter() << " km." << endl;
		cout << p[i].getName() << " is " << p[i].getDist() << " AU from the Sun." << endl;
		cout << " --- " << endl;
	}


	/// Part 3: Solar System

	solarSystem sol("Sol");

	cout << "System name: " << sol.getName() << endl;

	// TODO: Add the four planets from part 2 to the solar system object
    for (int i = 0; i < 4; i++){
        sol.addPlanet(pnt[i],rad[i],dis[i]);
	}

	// Use the following print statements to test your solar system class code
	cout << sol.getName() << " has " << sol.getNumPlanets() << " planets." << endl;
	cout << "The biggest planet is " << sol.findLargest() << "." << endl;
	cout << "The diameter of " << sol.getName() << " is " << sol.getDiameter() << " AU." << endl;


	return 0;
}
