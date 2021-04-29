// Ashley Nixon
// 07/09/2019
//Exception Handling and Vectors
// menu driven program that will test handling of exceptions using the "try/catch" block. 

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 10
using namespace std;

struct MyException : public exception {
	const char * what() const throw () {
		return "This is a custom user thrown C++ Exception";
	}
};

int showChoices();
double zeroException(double, double);
void employeeIDException();
void userCustomException(int var);
int countDigit(long long n);

int main(void ) {
	while (true) {
		int choice;
		try {
			choice = showChoices();
		}
		catch (const exception& obj) {
			cout << "Exception Caught" << endl;
			cout << obj.what() << endl; //if not a proper number, show 
			continue;
		}
		if (choice == 4) break;
		switch (choice) {
		case 1: {
			double numerator; double denominator; double result;
			cout << "Enter the first number(Numerator): ";
			cin >> numerator;
			cout << "Enter the second number (Denominator): ";
			cin >> denominator;
			try {
				result = zeroException(numerator, denominator);
				//cout << "testing" << endl; was having issue here with hanging, figured out issue
			}
			catch (const exception& obj) {
				cout << "Exception Caught" << endl;
				cout << obj.what() << endl << endl;
				break;
			}
			cout << result << endl << endl;
			break;
		}
		case 2: {
			cout << endl;
			try {
				userCustomException(0);
			}
			catch (const exception& obj) {
				cout << "Exception Caught" << endl;
				cout << obj.what() << endl << endl;
				break;
			}
			break;
		}
		case 3: {
			try {
				employeeIDException();
			}
			catch (const int count) {
				cout << "Exception Caught" << endl;
				if (count > 9) { //more than nine, not fine
					cout << "The length of the Employee ID is " << count << " which exceeds the maximum length of 9 characters allowed. Please try again!" << endl << endl;
				}
				else { //less than 9, also not fine
					cout << "The length of the Employee ID is " << count << " which is LESS the maximum length of 9 characters allowed. Please try again!" << endl << endl;
				}
				break;
			}
			catch (const exception& obj) {
				cout << "Exception Caught" << endl;
				cout << obj.what() << endl << endl;
				break;
			}
		}
		}
	}
	system("pause");
	return 0;
}

//showChoices();
//menu options:
//1. Test Division by Zero Excpetion
//2. Test User Custom Exception
//3. Test Employee ID Exception
//4. Exit
int showChoices() {
	int choice;
	cout << "\tMENU:" << endl;
	cout << " 1:  Test Division by Zero Exception " << endl;
	cout << " 2:  Test User Custom Exception " << endl;
	cout << " 3:  Test Employee ID Exception " << endl;
	cout << " 4:  Exit " << endl;
	cout << " Enter your choice: ";
	cin >> choice;
	if (choice > 4 || choice < 1)
		throw exception("Number is not correct. Try again!"); //not a choice of 1 - 4
	return choice;
}

//zeroException();
double zeroException(double num, double denom) {
	if (denom == 0) {
		throw exception("Division by zero condition is not allowed! Please try again");
	}
	return num / denom;
}

//employeeIDException();
void employeeIDException() {
	long search;
	long employeeIDs[SIZE] = { 123456789, 111555777, 163591467, 222222222, 354914023, 360753618, 435315204, 494458904, 870900162, 951765995}; //10 employee ID's with proper length, must be in proper order for binary search
	vector<long> employeeIDsVector;
	for (int i = 0; i < SIZE; i++) {
		employeeIDsVector.push_back(employeeIDs[i]);
	}
	cout << "\nEnter employee ID to search: " << endl; //request ID to search for
	cin >> search;
	int countOfDigit = countDigit(search);
	if (countOfDigit != 9) {
		throw countOfDigit; //determine if proper length
	}
	if (binary_search(employeeIDsVector.begin(), employeeIDsVector.end(), search) == false) {
		throw exception("The Employee ID you entered is INVALID. Please try again"); //proper length but not listed
	}
	cout << "The Employee ID that you entered was found" << endl << endl; //proper length and listed
}

//userCustomException();
void userCustomException(int var) {
	if (var == 0) {
		throw MyException(); //throw the custom exception
	}
}

int countDigit(long long n) {
	if (n == 0)
		return 0;
	return 1 + countDigit(n / 10);
}


