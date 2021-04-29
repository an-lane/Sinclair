// tutorialU4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>

using namespace std;

void nameSlice(char[]);

int main()
{
	const int SIZE = 41;
	char name[SIZE];

	cout << "enter information: ";
	cin.getline(name, SIZE);
	nameSlice(name);

	cout << "you entered " << name[0] << endl;
	cout << name[1] << endl;
	cout << name[3] << endl;
	return 0;
	
}

void nameSlice(char userName[]) {
	int count = 0;

	while (userName[count] != ',' && userName[count] != '\0')
		count++;

	if (userName[count] == ',')
		userName[count] = '\0';
}
