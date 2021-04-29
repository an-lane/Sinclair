/*
Ashley Nixon
6/-22-2019
Customer Contact Application
Program that uses an array of nested structs to store the addresses for your store's customers.
*/

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

//variable to hold how many customers are entered
int index = 0;

//address struct
struct Address {
	string street;
	string city;
	string state;
	string zip;
};

//customer struct
struct Customer {
	string lastNm, firstNm;
	Address homeAdd, busAdd;
};

//declaration of functions
int displayMenu();
Customer getCustomer();
void showCustomer(Customer);
void allCustomers(Customer[]);
Address getAddress();
void findCust(Customer[], int);

int main() {
	//array of customer struct
	Customer cust[100];

	//menu to be shown until exited
	while (true) {
		//call dsiplayMenu function and get choice
		//call function based on choice
		int choice = displayMenu();
		switch (choice) {
			case 1:
				cust[index] = getCustomer();
				index++;
				break;
			case 2:
				allCustomers(cust);
				break;
			case 3:
				findCust(cust, index);
				break;
			case 4:
				cout << "Program Terminated." << endl;
				return 0;
				break;
			default:
				cout << "Invalid selection, please re-select menu option." << endl;
		}
		//cout << endl;
	}
	return 0;
}

int displayMenu() {
	cout << "Customer Contacts Menu\n"
		<< "\nSelect from the menu below\n"
		<< " 1.  Enter new customer\n"
		<< " 2.  Display all customers\n"
		<< " 3.  Display a particular customer\n"
		<< " 4.  Exit program" << endl;

	int choice;

	cout << "Choice:: ";
	cin >> choice;
	cin.ignore();
	cout << endl;
	return choice;
}

Address getAddress() {
	//get user's data for street, city, state, and zipcode and store in appropriate variables of addresses
	//return address
	Address a;
	cout << "Enter Street Address: ";
	getline(cin, a.street);
	cout << "Enter City: ";
	getline(cin, a.city);
	cout << "Enter State: ";
	getline(cin, a.state);
	cout << "Enter zip code: ";
	getline(cin, a.zip);
	return a;
}

Customer getCustomer() {
	//First name, last name and two addresses
	Customer c;
	cout << "Enter First Name: ";
	getline(cin, c.firstNm);
	cout << "Enter Last Name: ";
	getline(cin, c.lastNm);
	cout << "Enter Business Address\n";
	c.busAdd = getAddress();
	cout << "Enter Home Address\n";
	c.homeAdd = getAddress();
	cout << endl;
	return c;
}

void showCustomer(Customer c) {
	//display customer details
	cout << "Customer Name: " << c.firstNm << " " << c.lastNm << endl;
	cout << "Business Address: " << endl;
	cout << "\t" << c.busAdd.street << " " << c.busAdd.city << ", " << c.busAdd.state << ", "
		<< c.busAdd.zip << endl;
	cout << "Home Address: " << endl;
	cout << "\t" << c.homeAdd.street << " " << c.homeAdd.city << ", " << c.homeAdd.state << ", "
		<< c.homeAdd.zip << endl;
	cout << endl;

}

void allCustomers(Customer cust[]) {
	//Iterate for loop till index(number of custoemrs entered)
	for (int i = 0; i < index; i++) {
		showCustomer(cust[i]);
		cout << endl;
	}
}

void findCust(Customer cust[], int size) {
	//Ask user to enter first and last name
	string firstName, lastName;
	cout << "Enter First Name: ";
	getline(cin, firstName);
	cout << "Enter Last Name: ";
	getline(cin, lastName);
	cout << endl;

	//Iterate the loop for all customers
	//return with information when fout, else not found
	for (int i = 0; i < size; i++) {
		if (cust[i].firstNm == firstName && cust[i].lastNm == lastName) {
			showCustomer(cust[i]);
			return;
		}
	}
	cout << "Customer not in list" << endl;
}

