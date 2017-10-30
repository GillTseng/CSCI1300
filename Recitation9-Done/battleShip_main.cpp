#include <iostream>
#include <string>
#include "battleShip.h"

using namespace std;

battleShip::battleShip(string ship_name){
    name = ship_name;
    hits = 0;
}

battleShip::~battleShip(){
}

void battleShip::setShipName(string ship_name){
    name = ship_name;
}

string battleShip::getShipName(){
    return name;
}

void battleShip::setSize(int ship_size){
    size = ship_size;
}

int battleShip::getSize(){
    return size;
}

void battleShip::recordHit(){
    hits++;
}

bool battleShip::isSunk(){
    if (size == hits){
        return size == hits;
    }
}

int main(){
	//TODO: Declare 3 instances of the battleship class: Destroyer Carrier Cruiser
    battleShip Destroyer("Destroyer");
    battleShip Carrier("Carrier");
    battleShip Cruiser("Cruiser");

	//TOD0: Give the ships a size: Destroyer-3 Carrier-5 Cruiser-2
	// you will need to call the appropriate methods
    Destroyer.setSize(3);
    Carrier.setSize(5);
    Cruiser.setSize(2);

	// Once you have this running for one, expand this while loop to include the other
	// two instances. Have the while loop end when all three ships have been sunk
	while(Destroyer.isSunk() == false || Carrier.isSunk() == false || Cruiser.isSunk() == false){
		Destroyer.recordHit();
		Carrier.recordHit();
		Cruiser.recordHit();
	}
}
