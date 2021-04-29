#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "ShipClass.h"
using namespace std;


class CruiseShip :public ShipClass {
public:
	//CruiseShip();
	CruiseShip(string name, int year, int maxPassenger);

	//setters and getters
	int getmaxPassenger();
	void setmaxPassenger(int maxPassenger);

	void print();
private:
	int maxPassenger;
};

#endif //CRUISESHIP_H