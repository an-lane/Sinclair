/*
Ashley Nixon
05/23/2019
BoxInventory
Box inventory opens a text file, reads the file into arrays, sorts the data by price (low to high), by box number (low to high), searches for a specific
box number and creates a reorder report.
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

//In the program, read the data into arrays. 
void loadArrays(double boxesI[], double boxQty[], double boxPrice[], int &length) { //loads correctly, needs some visual cleanup...
	//try just copying and pasting the whole other 
	ifstream boxes("boxinv.txt");
	double bn;
	double bs, bp;

	length = 0;

	if (!boxes) {
		cout << "Unable to laod file. Please check boxinv.txt\n";
		length = -1;
		return;
	}
	while (boxes >> bn >> bs >> bp) {
		boxesI[length] = bn;
		boxQty[length] = bs;
		boxPrice[length] = bp;
		length++;
	}
	return;
}

//Display the data
void showArrays(double boxesI[], double boxQty[], double boxPrice[], int &length) {
	for (int i = 0; i < length; i++) {
		cout << setprecision(0) << fixed;
		cout << boxesI[i] << "\t\t   "<< boxQty[i] << "\t\t$" << setprecision(2) << boxPrice[i] << endl;
	}
}

//Sort the data by price, low to high -good
void sortPrice(double boxesI[],double boxQty[], double boxPrice[], int &length) { 
	double temp;
	double temp2, n;
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (boxPrice[i] > boxPrice[j]) {
				temp = boxesI[i];
				temp2 = boxQty[i];
				n = boxPrice[i];

				boxesI[i] = boxesI[j];
				boxQty[i] = boxQty[j];
				boxPrice[i] = boxPrice[j];

				boxesI[j] = temp;
				boxQty[j] = temp2;
				boxPrice[j] = n;
			}
		}
	}
	//cout << "\n";
}

//Sort the data by box number, low to high -good
void sortBox(double boxesI[], double boxQty[],double boxPrice[], int &length) { 
	double temp;
	double temp2, n;
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (boxesI[i] > boxesI[j]) {
				temp = boxesI[i];
				temp2 = boxQty[i];
				n = boxPrice[i];

				boxesI[i] = boxesI[j];
				boxQty[i] = boxQty[j];
				boxPrice[i] = boxPrice[j];

				boxesI[j] = temp;
				boxQty[j] = temp2;
				boxPrice[j] = n;
			}
		}
	}
	//cout << "\n";
}

//Look up the price of a box given the box number 
void lookUpPrice(double boxn, double boxesI[], double boxPrice[], int &length) { 
	for (int i = 0; i < length; i++) {
		if (boxesI[i] == boxn) {
			cout << setprecision(0) << fixed;
			cout << "\nThe price of box " << boxn << " is $" << setprecision(2) << boxPrice[i] << "\n" << endl;
			return;
		}
	}
	cout << "\nUnable to locate " << boxn << ". Please double check the inventory number.\n" << endl;
	return;
}

//Reorder report. Report any item with number of boxes below 100. Sort the output from high to low.
void reorderReport(double boxesI[], double boxQty[], double boxPrice[], int &length) { 
	double temp;
	double temp2;
	double n;
	double x;
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (boxQty[i] < boxQty[j]) {
				temp = boxesI[i];
				temp2 = boxQty[i];
				n = boxPrice[i];

				boxesI[i] = boxesI[j];
				boxQty[i] = boxQty[j];
				boxPrice[i] = boxPrice[j];

				boxesI[j] = temp;
				boxQty[j] = temp2;
				boxPrice[j] = n;
			}
		}
		if (boxQty[i] < 100) {
			cout << setprecision(0) << fixed;
		cout << boxesI[i] << "\t\t   " << boxQty[i] << setprecision(2) << "\t\t$" << boxPrice[i] << endl;

		}
	}

}


int showMenu()
{
	cout << "Box Inventory System" << "\n" << endl;
	int choice;
	cout << "1: Display the box inventory\n";
	cout << "2: Sort boxes by price, ascending\n";
	cout << "3: Sort boxes by box number, ascending\n";
	cout << "4: Display a box's price\n";
	cout << "5: Produce the reorder report\n";
	cout << "6: Exit\n";
	cout << "Enter your choice: ";
	cin >> choice;
	cout << "\n";
	return choice;
}

int main()
{
	double boxesI[20];
	double boxQty[20];
	double boxPrice[20];
	int length = -1;
	int choice;
	double boxn;

	loadArrays(boxesI, boxQty, boxPrice, length);
	if (length == -1) {
		return 0;
	}

	choice = showMenu();
	while (choice != 6) {
		if (choice == 1) {
			cout << "\n";
			cout << "Box Inventory List\n";
			cout << "Box Number\tNumber Boxes\tPrice per box\n";
			showArrays(boxesI, boxQty, boxPrice, length);
			cout << "\n";
		}
		else if (choice == 2) {
			cout << "Sorted by Price low to high\n";
			cout << "Box Number\tNumber Boxes\tPrice per box\n";
			sortPrice(boxesI, boxQty, boxPrice, length);
			showArrays(boxesI, boxQty, boxPrice, length);
			cout << "\n";
		}
		else if (choice == 3) {
			cout << "Sorted by box number low to high\n";
			cout << "Box Number\tNumber Boxes\tPrice per box\n";
			sortBox(boxesI, boxQty, boxPrice, length);
			showArrays(boxesI, boxQty, boxPrice, length);
			cout << "\n";
		}
		else if (choice == 4) { 
			sortBox(boxesI, boxQty, boxPrice, length); //sort the array by box, high to low
			cout << "Box price search\n";
				cout << "Enter box number to search:";
				cin >> boxn;
				cout << "\n";
				lookUpPrice(boxn, boxesI, boxPrice, length);
		}
		else if (choice == 5) { 
			cout << "Low inventory report\n";
			reorderReport(boxesI, boxQty, boxPrice, length);
			cout << "\n";
		}
		else {
			
			cout << "\nInvalid choice- try again\n\n";
		}
		choice = showMenu();
	}
	system("pause");
	return 0;
}

