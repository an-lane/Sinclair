// Ashley Nixon
// 07/06/2019
#include "pch.h"
#include"ShipClass.h"
#include<iostream>
using namespace std;

/*parametrized constructor to set values to data members
I saw both ways written out in various coding texts,
I commented out the second way, but find the way it is
written currently much less confusing.*/
ShipClass::ShipClass(string name, int year)/*:name(name),year(year)*/ {
	this->name = name;
	this->year = year;
}

//setters and getters

//Default constrctor-- not really needed so removed.
//ShipClass::ShipClass():name(""),year(0){}

//get name
string ShipClass::getName() {
	return name;
}
//set name
void ShipClass::setName(string name) {
	name = name;
}

//get year
int ShipClass::getYear() {
	return year;
}
//set year
void ShipClass::setYear(int year) {
	year = year;
}


//print
void ShipClass::print() {
	cout << "Ship Name: " << getName() << endl;
	cout << "Year Built: " << getYear() << endl;
}

