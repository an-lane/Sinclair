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
using namespace std;

//In the program, read the data into arrays.
void loadArrays(string boxesI[], double boxPrice[], int &length) {

	ifstream boxes("boxinv.txt");
	string bn, bs;
	double bp;
	length = 0;

	if (!boxes) {
		cout << "Unable to laod file. Please check boxinv.txt\n";
		length = -1;
		return;
	}
	while (boxes >> bn >> bs >> bp) {
		boxesI[length] = bn + " " + bs;
		boxPrice[length] = bp;
		length++;
	}
	return;
}

 //Display the data
void showArrays(string boxesI[], double boxPrice[], int &length) {
	for (int i = 0; i < length; i++) {
		cout << boxesI[i] << " " << boxPrice[i] << endl;
	}
}

 //Sort the data by price, low to high
void sortPrice(string boxesI[], double boxPrice[], int &length) {
	string temp;
	double n;
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (boxPrice[i] > boxPrice[j]) {
				temp = boxesI[i];
				n = boxPrice[i];
				boxesI[i] = boxesI[j];
				boxPrice[i] = boxPrice[j];
				boxesI[j] = temp;
				boxPrice[j] = n;
			}
		}
	}
	cout << "\n";
}

 //Sort the data by box number, low to high
void sortBox(string boxesI[], double boxPrice[], int &length) {
	string temp;
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (boxesI[i] > boxesI[j]) {
				temp = boxesI[i];
				boxesI[i] = boxesI[j];
				boxesI[j] = temp;
			}
		}
	}
	cout << "\n";
}

 //Look up the price of a box given the box number (do a binary search)
void lookUpPrice(string boxn, string boxesI[], double boxPrice[], int &length) {
	for (int i = 0; i < length; i++) {
		if (boxesI[i] == boxn) {
			cout << "\nThe price of " << boxn << " is " << boxPrice[i] << "\n" << endl;
			return;
		}
	}
	cout << "Unable to locate " << boxn << ". Please double check the inventory number.\n" << endl;
	return;
}

 //Reorder report. Report any item with number of boxes below 100. Sort the output from high to low.
 //Exit the programvoid reorderReport(string boxesI[], double boxPrice[], int &length) {
	string temp="";
	double n=0;
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (boxPrice[i] < boxPrice[j]) {
				temp = boxesI[i];
				n = boxPrice[i];
				boxesI[i] = boxesI[j];
				boxPrice[i] = boxPrice[j];
				boxesI[j] = temp;
				boxPrice[j] = n;
			}
		}
	} 
	cout << "\n";
}


int showMenu() {
	int choice;
	cout << "1: Display the box inventory\n";
	cout << "2: Sort boxes by price, ascending\n";
	cout << "3: Sort boxes by box number, ascending\n";
	cout << "4: Display a box's price\n";
	cout << "5: Produce the order report\n";
	cout << "6: Exit\n";
	cout << "Please enter your selection: ";
	cin >> choice;
	return choice;
}

int main()
{
	string boxesI[20];
	double boxPrice[20];
	int length = -1;
	int choice;
	string boxn;


	loadArrays(boxesI, boxPrice, length);
	if (length == -1) {
		return 0;
	}
	choice = showMenu();
	while (choice != 6) {
		if (choice == 1) {
			std::cout << "\n";
			showArrays(boxesI, boxPrice, length);
			std::cout << "\n";
		}
		else if (choice == 2) {
			sortPrice(boxesI, boxPrice, length);
		}
		else if (choice = 3) {
			sortBox(boxesI, boxPrice, length);
		}
		else if (choice = 4) {
			std::cout << "Enter box number: ";
			cin >> boxn;

			lookUpPrice(boxn, boxesI, boxPrice, length);
		}
		else if (choice = 5) {
			reorderReport(boxesI, boxPrice, length);
		}
		else {
			std::cout << "\nInvalid choice- try again\n\n";
		}
		choice = showMenu();
	}
}

