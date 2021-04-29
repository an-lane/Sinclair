/*
Ashley Nixon
05-23-2019
County Auditor
Program for the county auditor that uses parallel arrays to input, print, search, find largest amount due and sort the tax data.
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//load arrays s1, s2 for address number and street name. n for amount due. using parallel arrays!
void loadArrays(string address[], double amtDue[], int &length) {

	ifstream prog("prog3.txt");
	string s1, s2;
	double n;

	length = 0;
	if (!prog) {
		cout << "Unable to load file. Please check prog3.txt\n";
		length = -1;
		return;
	}
	while (prog >> s1 >> s2 >> n) {
		address[length] = s1 + " " + s2;
		amtDue[length] = n;
		length++;
	}
	return;
}

void showArrays(string address[], double amtDue[], int length) { //read the arrays
	for (int i = 0; i < length; i++) {
		cout << address[i] << " " << amtDue[i] << endl;
	}
}

void lookUpTaxes(string addr, string address[], double amtDue[], int length) { //locate the specific address enterd by user and provide the amount due.
	for (int i = 0; i < length; i++) {
		if (address[i] == addr) {
			cout << "\nThe taxes for " << addr << " = " << amtDue[i] << "\n" << endl;
			return;
		}
	}
	cout << addr << " Address not found.\n"; //return to menu if address not found
	return;
}

void sortTaxes(string address[], double amtDue[], int length) { //selection sort parallel arrays
	string temp;
	double n;
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (amtDue[i] > amtDue[j]) {
				temp = address[i];
				n = amtDue[i];
				address[i] = address[j];
				amtDue[i] = amtDue[j];
				address[j] = temp;
				amtDue[j] = n;
			}
		}
	}
	cout << "\n";
}

int showMenu() { //menu! return to the choice made
	int choice;
	cout << "County Auditors Property Sort and Search\n\n";
	cout << "1: Display the Property Tax Data\n";
	cout << "2: Lookup taxes for a particular address\n";
	cout << "3: Sort tax amounts in ascending order\n";
	cout << "4: Display property with largest tax due\n";
	cout << "5: Exit\n";
	cout << "Please enter your selection: ";
	cin >> choice;
	return choice;
}

void biggestTaxes(string address[], double amtDue[], int length) { //pick out the address with largest tax amount
	double max = amtDue[0];
	int index = 0;
	for (int i = 0; i < length; i++) {
		if (amtDue[i] > max) {
			max = amtDue[i];
			index = i;
		}
	}
	cout << "\nThe largest tax amount = " << amtDue[index] << " at " << address[index] << "\n" << endl;
}

int main() { //user preference is else! this is for menu execution.
	string address[20];
	double amtDue[20];
	int length = -1;
	int choice;
	string addr;
	loadArrays(address, amtDue, length);
	if (length == -1) {
		return 0;
	}
	choice = showMenu();
	while (choice != 5) {
		if (choice == 1) {
			cout << "\n";
			showArrays(address, amtDue, length);
			cout << "\n";
		}
		else if (choice == 2) {
			cout << "Enter address: ";
			cin.ignore();
			getline(cin, addr);

			lookUpTaxes(addr, address, amtDue, length);
		}
		else if (choice == 3) {
			sortTaxes(address, amtDue, length);
		}
		else if (choice == 4) {
			biggestTaxes(address, amtDue, length);
		}
		else {
			cout << "\nInvalid choice - try again\n\n";
		}
		choice = showMenu();
	}
}