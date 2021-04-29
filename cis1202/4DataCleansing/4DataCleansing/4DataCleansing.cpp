/*
Ashley Nixon
06/21/2019
DataCleansing
Write a program that reads data from the csv file, prog4.txt and stores the data in an array. 
The program should read the data and verify that the first letter of the first and last name 
are capitalized and the date is in the correct format.
*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int displayMenu();
void showFileDate(string);
void showFileDateCleansed(string);

/*
Outputs the menu selections
inputs the user selection
validates that the user has entered a valid selection
*/

int displayMenu() {
	int choice;
	cout << "MENU\n"
		<< "1.  Read and show file data as is\n"
		<< "2.  Show file data cleansed\n"
		<< "3.  Exit the program\n"
		<< endl;

	cout << "Enter your choice: ";
	cin >> choice;
	if (choice < 1 or choice>3) {
		cerr << "Error. Please enter choice 1, 2, or 3." << endl;
		choice = displayMenu();
		}
	return choice;
}

/*
Out data in a tabular form directly from the file as is.
Takes an argument of file name.
*/

void showFileDate(string fname) {
	//Define a userData array that you can store each row's data into
	string userData[100];
	int size = 0;

	cout << "-------------------------------------------------------\n";
	cout << "|FirstName             Last Name              EU-Date |\n";
	cout << "-------------------------------------------------------\n";

	string content;

	//Use the ifstream object to read file data into the array
	ifstream file(fname);
	if (file.is_open()) {

		//read all lines and fill the vector
		while (getline(file, content)) {
			userData[size++] = content;
			//Define a rowData array to store the seperate elements of each row into (this will allow you to easily apply string manipulations to each element of the array)
			string rowData[4];
			stringstream lineStream(content); //Transforms the line into string stream

			//get fields from the string stream to the struct fields; data is seperated by comma;
			getline(lineStream, rowData[0], ',');
			getline(lineStream, rowData[1], ',');
			getline(lineStream, rowData[2], '\r');
			cout << "|" << setw(15) << left << rowData[0] << setw(15) << right << rowData[1]
				<< setw(23) << right << rowData[2] << "|" << endl;

		}
		cout << "-------------------------------------------------------\n";
	}
	else {
		//show error message
		cerr << "File not found!";
		cin.get();
		exit(0);
	}
	file.close();
}
/*
Outputs the data into a tabular form with the first letter capitalized for the first and last name columns, 
also in this option must create additional column labeled USA-Date, this column must use the EU-Date column,
and convert the date from dd-mm-yyyy to USA standard mm-dd-yyyy. Ensure that a day or month is less
than 10, a leading zero is accounted for and added.
*/

void showFileDateCleansed(string fname) {
	//Define a userData array that you can store each row's data into
	string userData[100];
	int size = 0;
	cout << "-------------------------------------------------------------------------------\n";
	cout << "|First Name          Last Name                EU-Date                USA-Date |\n";
	cout << "-------------------------------------------------------------------------------\n";

	//use any additional variables you see fit to accomplish the tasks
	string content;
	ifstream file(fname);
	if (file.is_open()) {

		//read all lines and get the vector
		while (getline(file, content)) {
			userData[size++] = content;

			//Define a rowData array to store the seperate elements of each row into 
			string rowData[4];
			stringstream lineStream(content); //transforms line into string

			//Get fields from the string stream to the struct fields; data is seperated by comma
			getline(lineStream, rowData[0], ',');
			getline(lineStream, rowData[1], ',');
			getline(lineStream, rowData[2], '\r');
			rowData[3] = rowData[2];
			rowData[0][0] = toupper(rowData[0][0]); //First name first letter to uppercase
			rowData[1][0] = toupper(rowData[1][0]); //Last name first letter to uppercase

			//convert EU-Date to USA-Date
			string forDate[3];
			stringstream lineStream1(rowData[3]); //transforms line into a string stream
			getline(lineStream1, forDate[0], '-');
			getline(lineStream1, forDate[1], '-');
			getline(lineStream1, forDate[2], '-');
			if (forDate[0].size() == 1)forDate[0] = "0" + forDate[0];
			if (forDate[1].size() == 1)forDate[1] = "0" + forDate[1];
			string dateUSA = forDate[1] + '-' + forDate[0] + '-' + forDate[2];

			cout << "|" << setw(20) << left << rowData[0] << setw(20) << left << rowData[1]
				<< setw(14) << right << rowData[2] << setw(23) << right << dateUSA << setw(1) << "|" << endl;

		}
		cout << "-------------------------------------------------------------------------------\n";
	}
	else {
		//show error message
		cerr << "Error, File not found!";
		cin.get();
		exit(0);
	}
	file.close();
}

int main(int argc, const char *argv[]) {

	while (true) {
		int choice = displayMenu();
		switch (choice) {
			case 1:
				showFileDate("prog4.txt");
				break;
			case 2:
				showFileDateCleansed("prog4.txt");
				break;
			case 3:
				cout << "Program Terminated." << endl;
				exit(EXIT_SUCCESS);
				break;
		}
	}
	return 0;
}




