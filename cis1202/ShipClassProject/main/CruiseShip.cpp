// Ashley Nixon
// 07/06/2019
#include "pch.h"
#include "CruiseShip.h"
#include "ShipClass.h"
#include<iostream>
using namespace std;

/*parametrized constructor to set values to data members 
I saw both ways written out in various coding texts, 
I commented out the second way, but find the way it is 
written currently much less confusing.*/
CruiseShip::CruiseShip(string name, int year, int maxPassenger) :ShipClass(name, year)/*,maxPassenger(maxPassenger)*/ {
	this->maxPassenger = maxPassenger;
}

//default constructor -- not really needed so removed.
//CruiseShip::CruiseShip():ShipClass("",0),maxPassenger(0){} 

//setters and getters
//get passenger
int CruiseShip::getmaxPassenger() {
	return maxPassenger;
}
//set passenger
void CruiseShip::setmaxPassenger(int maxPassenger) {
	this->maxPassenger = maxPassenger;
}

//print details
void CruiseShip::print() {
	cout << "Ship Name:" << getName() << endl;
	cout << "Year Built: " << getYear() << endl;
	cout << "Maximum Passengers: " << getmaxPassenger() << endl;
}