//Ashley Nixon
//06/05/2019
//DataCleansing
//Program that reads data from the csv file, prog4.txt and stores the data in an array. verifies and cleans the data 

#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int displayMenu() { //outputs menu selections, inputs the users selection, validates that the user has entered a valid selection
	int choice;
	cout << "Menu\n";
	cout << "1:  Read and show File Data as is\n";
	cout << "2:  Show File Data Cleansed\n";
	cout << "3:  Exit\n";
	cout << "Enter your choice:  ";
	cin >> choice;
	return choice;
}

/*
void userData(char rawData[], int &line) { // array that stores each rows data into
	//ifstream object to read data into the array
	ifstream prog("prog4.txt");
	

	if (!prog) {
		cout << "Unable to load file, please check prog4.txt" << endl;
		line = -1;
		return;
	}
	while (prog >> rawData) {
		prog.getline(cin,rawData);

	}

}*/

long rowData(char[], int) {
	return 0;
}


void showFileDate(char firstN[], char lastN[], char dateEU[], int &line) { //(string) outputs the data in a tabular form direction from the file as is. this method takes an argument of file name.
	for (int i = 0; i < line; i++) {
		cout << firstN[i] << lastN[i] << dateEU[i] << endl;
	}
}

void showFileDateCleansed() { //outputs the data in tabular form with the first letter capitalized for the first and last name columns, additonal column for usa standard date. argument file name

}

int main() {
	int choice;
	int line = -1;
	char rawData[80];

	ifstream prog("prog4.txt");
	//userdata array, ifstring, rowdata arrray. 
	

	if (line == -1) {

		if (!prog) {
			cout << "Unable to load file, please check prog4.txt" << endl;
			line = -1;
			return;
		}
		while (prog >> rawData) {
			prog.getline(cin, rawData);

		}
		return 0;
	}



	
	choice = displayMenu();
	while (choice != 3) {
		if (choice == 1) {
			cout << "----------------------------------------------------\n";
			cout << "|First Name\tLast Name\tEU-Date |\n";
			showFileDate(rawData, line);
			cout << "----------------------------------------------------\n";
		}
		else if (choice ==2) {
			cout << "-----------------------------------------------------\n";
			cout << "|First Name\tLast Name\tEU-Date\tUSA-Date |\n";

			cout << "-----------------------------------------------------\n";
		}
		else {
			cout << "Invalid choice - try again\n";
		}choice = displayMenu();
	}
	system("pause");
	return 0;
}



