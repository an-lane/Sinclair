// Ashley Nixon
// 07/06/2019
#ifndef CARGOSHIPCLASS_H
#define CARGOSHIPCLASS_H
#include "ShipClass.h"
using namespace std;

class CargoShipClass :public ShipClass {
public:
	//CargoShipClass();
	CargoShipClass(string name, int year, int capacity);

	//setters and getters
	int getCapacity();
	void setCapacity(int capacity);

	void print();

private:
	int capacity;
};

#endif //CARGOSHIPCLASS_H