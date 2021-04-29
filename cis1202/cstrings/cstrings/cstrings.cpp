//Ashley Nixon
//6-6-2019
//C-strings homework

#include "pch.h"
#include <iostream>
//#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int findW(char[], int);
long getCustNum(char[], int);
int getYear(char str[], int start);

int main()
{
	int strLength, wPointer;
	//string custNumber, year, workOrderNumber;
	long custNumber;
	char workOrderNumber[6];
	int year;

	char workOrder[] = "91800w940770";

	strLength = strlen(workOrder);
	//strLength = workOrder.length();
	wPointer = findW(workOrder, strLength);
	//wPointer = workOrder.find('w', 0);
	custNumber = getCustNum(workOrder, wPointer);
	//custNumber.assign(workOrder, 0, wPointer);
	year = getYear(workOrder, wPointer + 1);
	//year.assign(workOrder, wPointer + 1, 2);
	strcpy(workOrderNumber, workOrder + wPointer + 3);
	//workOrderNumber.assign(workOrder, wPointer + 3, strLength);

	cout << "The length is " << strLength << endl;
	cout << "The location of the w is " << wPointer << endl;
	cout << "The customer number is " << custNumber << endl;
	cout << "The year of the order is " << year << endl;
	cout << "The order number is " << workOrderNumber << endl;

	system("pause");
	return 0;
}

int findW(char str[], int len) {
	for (int i = 0; i < len; i++) {
		if (str[i] == 'w')
			return i;
	}
	return -1;
}

long getCustNum(char str[], int wIndex) {
	char cnum[7];
	strncpy(cnum, str, wIndex);
	return atol(cnum);
}

int getYear(char str[], int start) {
	char year[3];
	strncpy(year, str + start, 2);
	return atoi(year);
}

