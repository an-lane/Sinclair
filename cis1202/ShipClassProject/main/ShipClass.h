//Ashley Nixon
//07-06-2019
//implementation of the ShipClass class

#ifndef SHIPCLASS_H
#define SHIPCLASS_H
#include <string>
using namespace std;

class ShipClass {
public:
	ShipClass(string name, int year);
	//setter and getter
	string getName();
	void setName(string name);
	int getYear();
	void setYear(int year);

	void print();

private:
	string name;
	int year;
};

#endif //SHIPCLASS_H