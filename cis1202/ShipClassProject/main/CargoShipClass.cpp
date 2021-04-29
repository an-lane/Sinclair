// Ashley Nixon
// 07/06/2019
#include "pch.h"
#include "CargoShipClass.h"
#include "ShipClass.h"
#include <iostream>
using namespace std;

/*parametrized constructor to set values to data members
I saw both ways written out in various coding texts,
I commented out the second way, but find the way it is
written currently much less confusing.*/
CargoShipClass::CargoShipClass(string name, int year, int capacity) :ShipClass(name, year)/*,capacity(capacity)*/ {
	this->capacity = capacity;
}

//default constructor-- not really needed so removed.
//CargoShipClass::CargoShipClass():ShipClass("",0),capacity(0){}

//setters and getters
//get capacity
int CargoShipClass::getCapacity() {
	return capacity;
}
//set capacity
void CargoShipClass::setCapacity(int capacity) {
	this->capacity = capacity;
}

//print details
void CargoShipClass::print() {
	cout << "Ship Name: " << getName() << endl;
	cout << "Year Built: " << getYear() << endl;
	cout << "Cargo Capacity: " << getCapacity() << endl;
}