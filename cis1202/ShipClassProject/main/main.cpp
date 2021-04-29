// Ashley Nixon
// 07/06/2019
//Ship Class Program
//A program using self-defined header files and demonstrates 3 classes
#include "pch.h"
#include <iostream>
#include <iomanip>
#include "ShipClass.h"
#include "CargoShipClass.h"
#include "CruiseShip.h"
using namespace std;

int main() {
	string name;
	int year, maxPassenger, capacity;

	//Ship
	cout << "Ship" << endl;
	cout << "Please Enter Ship Name: ";
	getline(cin, name);

	cout << "Please Enter Year Built: ";
	cin >> year;

	ShipClass s(name, year);
	cin.ignore();

	//ship information
	cout << "\nShip Information" << endl;
	s.print();

	//cruise ship
	cout << "\nCruise Ship" << endl;
	cout << "Please Enter Cruise Ship Name: ";
	getline(cin, name);

	cout << "Please Enter Year Built: ";
	cin >> year;

	cout << "Please Enter Miximum Passenger Capacity: ";
	cin >> maxPassenger;

	CruiseShip csc(name, year, maxPassenger);
	cin.ignore();

	//cruise ship information
	cout << "\nCruise Ship Information" << endl;
	csc.print();

	//cargo ship
	cout << "\nCargo Ship" << endl;
	cout << "Please Enter Cargo Ship Name: ";
	getline(cin, name);

	cout << "Please Enter Year Built: ";
	cin >> year;

	cout << "Please Enter Cargo Capacity In Tonnage: ";
	cin >> capacity;

	CargoShipClass cs(name, year, capacity);
	cin.ignore();	

	//cargo ship information
	cout << "\nCargo Ship Information " << endl;
	cs.print();


	return 0;

}