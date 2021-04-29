/*
Ashley Nixon
06-25-2019
Fund Data
A menu-driven program that creates and updates the fundData.dat file. 
*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;

//maximum size of the string fields & file name of the string fields
#define SIZE 90
#define FILE_NAME "fundData.dat"

struct FundData {
	char fundName[SIZE]; //Fund Name
	char fundInception[SIZE]; //Fund inception date
	double ytd; //Year to date return as percent
	double oneYear; //1 year Return as percent
	double threeYear; //3 year Return as percent
	double fiveYear; //5 year Return as percent
	double tenYear; //10 year Return as percent
	double fundExpense; //Fund Yearly Expense as percent
};

//functions to follow...

void pressEnter() {
	cout << endl << "Press Enter to continue...";
	while (cin.get() != '\n') {};
}

//show proper record in tabular form
void showRecord(struct FundData data) {
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|Fund Name                            Fund Inception  YTD (Year to Date)  1 Year  2 Year  5 Year  10 Year  Net Expense|" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(35) << left << data.fundName << setw(14) << right << data.fundInception
		<< setw(23) << fixed << setprecision(2) << data.ytd
		<< setw(8) << data.oneYear << setw(8) << data.threeYear
		<< setw(8) << data.fiveYear << setw(8) << data.tenYear
		<< setw(8) << data.fundExpense << endl;
}

//displays menu, input user's selection, validate user's selection
int showMenu() {
	int userEntry = 0;
	bool badEntry = true;

	//display menu
	cout << endl << " * * * * M A I N   M E N U * * * * " << endl << endl;
	cout << "1.  Enter a new Fund Data\n"
		<< "2.  Delete a Fund Data\n"
		<< "3.  Change a Fund Data\n"
		<< "4.  Display All Fund Data\n"
		<< "5.  Exit The Program" << endl << endl;

	do {
		//input users selection
		cout << "Enter your choice (1-5): ";
		
		//validate the user's selection
		cin >> userEntry;

		badEntry = cin.fail() || userEntry < 1 || userEntry > 5;

		if (cin.fail()) {
			cin.clear();
		}
		cin.ignore(100, '\n'); //clear all line from cin
	} while (badEntry);

	switch (userEntry) {
		case 1:
			cout << endl << "You selected to Enter new Fund Data." << endl;
			break;
		case 2:
			cout << endl << "You selected to Delete Fund Data." << endl;
			break;
		case 3:
			cout << endl << "You selected to Change Fund Data." << endl;
			break;
		case 4:
			cout << endl << "You selected to display All Fund Data." << endl;
			break;
		case 5:
			cout << endl << "You selected to Exit the program." << endl;
			break;
	}

	return userEntry;
}

//write record to file
void setInfo() {
	struct FundData data;
	memset((char*)&data, 0, sizeof(struct FundData));

	ofstream outFile(FILE_NAME, ios::out | ios::binary | ios::app);

	//check if file exists
	if (outFile.is_open())
	{
		//enter user's data based on the Struct above into the file
		cout << endl << "Please enter the following information for the new Fund Data:" << endl;
		cout << "Fund Name: ";
		cin.getline(data.fundName, sizeof(data.fundName));
		cout << "Fund Inception Date Ex. mm/dd/yyyy: ";
		cin.getline(data.fundInception, sizeof(data.fundInception));
		cout << "Please enter the YTD (Year To Date Return as a percentage Ex. 5.2): ";
		cin >> data.ytd;
		cout << "Please enter one Year return (as a percentage EX. 8.0): ";
		cin >> data.oneYear;
		cout << "Please enter three Year return (as a percentage EX. 12.4): ";
		cin >> data.threeYear;
		cout << "Please enter five Year return (as a percentage EX. 9.0): ";
		cin >> data.fiveYear;
		cout << "Please enter ten Year return (as a percentage EX. 5.5): ";
		cin >> data.tenYear;
		cout << "Please enter Yearly Fund Expense (as a percentage EX. 1.5): ";
		cin >> data.fundExpense;

		//clear unread characters from cin
		cin.ignore(100, '\n');

		outFile.write((char*)&data, sizeof(struct FundData));

		//close the file
		outFile.close();

		cout << endl << "Record written to file." << endl;
	}
	else {
		cout << "Can't open the data File" << endl << endl;
	}
	pressEnter();
}

//find a record & return file position for editing
void search() {
	char fundName[SIZE];
	struct FundData data;
	long position;

	//check if file exist and open file
	fstream dataFile(FILE_NAME, ios::in | ios::out | ios::binary);
	if (dataFile.is_open()) {
		//get search user's search pattern
		cout << endl << "Enter all or part of the Fund Name: ";
		cin.getline(fundName, sizeof(fundName));

		//search for a record with given fund name
		position = -1;
		while (position == -1 && !dataFile.eof() && dataFile.read((char*)&data, sizeof(struct FundData))) {
			//compare search pattern fundName and proper field read from the file
			if (strstr(data.fundName, fundName) != NULL) {
				position = dataFile.tellg();
				position -= sizeof(struct FundData);
			}
		}

		if (position == -1) {
			cout << endl << "Record not found." << endl;
		}
		else {
			//show record been found
			cout << endl << "RECORD CONTENTS: " << endl;
			showRecord(data);
			pressEnter();

			cout << endl << "ENTER NEW CONTENTS: " << endl;
			cout << "Fund Name: ";
			cin.getline(data.fundName, sizeof(data.fundName));
			cout << "Fund Inception Date Ex. mm/dd/yyyy: ";
			cin.getline(data.fundInception, sizeof(data.fundInception));
			cout << "Please enter the YTD (Year To Date Return as a percentage Ex. 5.2): ";
			cin >> data.ytd;
			cout << "Please enter one Year return (as a percentage EX. 8.0): ";
			cin >> data.oneYear;
			cout << "Please enter three Year return (as a percentage EX. 12.4): ";
			cin >> data.threeYear;
			cout << "Please enter five Year return (as a percentage EX. 9.0): ";
			cin >> data.fiveYear;
			cout << "Please enter ten Year return (as a percentage EX. 5.5): ";
			cin >> data.tenYear;
			cout << "Please enter Yearly Fund Expense (as a percentage EX. 1.5): ";
			cin >> data.fundExpense;

			//clear unread characters from cin
			cin.ignore(100, '\n');

			//place write pointer to the proper position
			dataFile.seekp(position);
			dataFile.write((char*)&data, sizeof(struct FundData));

			//close the file
			dataFile.close();

			cout << endl << "Record written to file." << endl;
		}
	}
	else {
		cout << "Can't open data File" << endl << endl;
	}

	pressEnter();
}

//delete one record
void deleteRec() {
	char fundName[SIZE];
	char answer;
	struct FundData data;
	bool dataDeleted = false;

	//check if flie exists and open file
	fstream dataFile(FILE_NAME, ios::in | ios::binary);
	ofstream tmpFile("temp.dat", ios::out | ios::binary);
	if (dataFile.is_open()) {
		//get search user's search pattern
		cout << endl << "Enter all or part of the Fund Name: ";
		cin.getline(fundName, sizeof(fundName));

		//look all file search for a record with a given fund name
		while (!dataFile.eof() && dataFile.read((char*)&data, sizeof(struct FundData))) {
			//compare search pattern fundName and proper field read from the file
			if (strstr(data.fundName, fundName) != NULL) {
				//show proper record
				showRecord(data);
				pressEnter();

				//prompt user to delete current record
				do {
					cout << endl << "ARE YOU SURE YOU WANT TO DELETE THIS RECORD? (Y/N) ";
					cin >> answer;
					cin.ignore(100, '\n');
				} while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');
				if (answer == 'Y' || answer == 'y') {
					//do not copy data record to the output temporary file
					dataDeleted = true;
				}
				else {
					//just copy data record to the output temporary file
					tmpFile.write((char*)&data, sizeof(struct FundData));
				}
			}
			else {
				//just copy data record to the output temporary file
				tmpFile.write((char*)&data, sizeof(struct FundData));
			}
		}//while

		//close both files
		dataFile.close();
		tmpFile.close();

		//if any records are deleted
		if (dataDeleted) {
			//rewrite all contents from the temporary file to the data file
			ofstream newDataFile(FILE_NAME, ios::trunc | ios::binary);
			ifstream tmpFile("temp.dat", ios::binary);
			while (!tmpFile.eof() && tmpFile.read((char*)&data, sizeof(struct FundData))) {
				//copy data record to the data file
				newDataFile.write((char*)&data, sizeof(struct FundData));
			}

			//close both files
			newDataFile.close();
			tmpFile.close();

			cout << endl << "Deletion successful." << endl;
		}

		//delete temporary file
		remove("temp.dat");

	}
	else {
		cout << "Can't open data File" << endl << endl;
	}
	//pressEnter();
}

//display all records
void showAll() {
	struct FundData data;

	cout << endl << "****Begin FundDate Record Listing****" << endl << endl;

	//open source file
	ifstream inFile(FILE_NAME, ios::in | ios::binary);
	if (inFile.is_open()) {
		//read one record from the file
		while (!inFile.eof() && inFile.read((char*)&data, sizeof(struct FundData))) {
			showRecord(data);
			pressEnter();
		}
		cout << endl << "File is empty." << endl;
	}
	else {
		cout << endl << "File is not found." << endl;
	}

	//close input file
	inFile.close();
	cout << endl << "***End FundDate Record Listing***" << endl << endl;
}

int main() {
	int menuEntry;

	do {
		menuEntry = showMenu();

		switch (menuEntry) {
			case 1:
				//Enter new Fund Data
				setInfo();
				break;
			case 2:
				//Delete Fund Data
				deleteRec();
				break;
			case 3:
				//change Fund Data
				search();
				break;
			case 4:
				//display all Fund Data
				showAll();
				break;
			default:
				break;
		}
	} while (menuEntry != 5);

	return 0;
}
