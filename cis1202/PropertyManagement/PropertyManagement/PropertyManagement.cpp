//Ashley Nixon 
//05-30-2019
//Property Management
//Program to take the data of 7 properties, display them, sort the rent low to high, display the total rents and memory locations.

#include "pch.h"
#include <iostream>
using namespace std;

/*
Void enterRents(int*, int)
Uses a for loop to input the rent amounts into an array using pointers (not
subscripts) to
access the array elements
*/

void enterRents(int *rents, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter rent amount " << i + 1 << ":    ";
		cin >> *(rents + i);
	}
	cout << "\n";
}

/*
Void displayRents (int*, int)
Uses a for loop to display the contents of the rents array using pointers (not
subscripts)
to access the array elements
*/ 

void displayRents(int *rents, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Rental property " << i + 1 << "  $" << *(rents + i) << "\n";
	}
	cout << "\n";
}

/*
Int sumRents (int*, int)
Uses a for loop to sum the contents of the rents array using pointers (not
subscripts) to access the array elements Returns the total
*/

int sumRents(int *rents, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(rents + i);
	}
	return sum;
}

/*
Void displayMemoryLocations (int*, int)
Uses a for loop to display the memory locations of the array elements
*/

void displayMemoryLocations(int *rents, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Memory address of cell " << i << " = " << (rents + i) << "\n";
	}
	cout << "\n";
}

/*
Void selectionSort (int*, int)
Sorts the rents array into ascending order using pointers (not subscripts) to access array elements
*/

void selectionSort(int *rents, int size) {
	int minIndex, minValue;
	for (int start = 0; start < (size - 1); start++) {
		minIndex = start;
		minValue =  *(rents + start);
		for (int index = start + 1; index < size; index++) {
			if (*(rents + index) < minValue) {
				minValue = *(rents + index);
				minIndex = index;
			}
		}
		int temp = *(rents + minIndex);
		*(rents + minIndex) = *(rents + start);
		*(rents + start) = temp;
	}
}

/*
Int getMenuItem()
Displays the menu
Inputs the user’s menu selection
Validates the user’s menu selection
Returns the user’s valid menu selection
*/
int getMenuItem() {
	cout << "\nSinclair Porperty Management company:\n" << endl;
	cout << "Select from the following menu:\n";
	cout << "1   Enter rent amounts\n";
	cout << "2   Display Rents\n";
	cout << "3   Sort rent amounts\n";
	cout << "4   Total rents\n";
	cout << "5   Display rent array memory locations\n";
	cout << "6   Exit program" << endl;

	int option, sum;
	cin >> option;
	return option;
}

//Main Program uses a while loop with embedded switch statement to call appropriate functions based on menu selection.
int main() {
	const int SIZE = 7; //declaring arrays and size
	int rents[SIZE];

	//menu and prompt
	
	int choice = getMenuItem();
	while (choice != 6) {
		if (choice == 1) {
			cout << "\n";
			enterRents(rents, SIZE);
		}
		else if (choice == 2) {
			cout << "\n";
			displayRents(rents, SIZE);
		}
		else if (choice == 3) {
			cout << "\n";
			selectionSort(rents, SIZE);
		}
		else if (choice == 4) {
			
			cout << "\nTotal rents = $"<< sumRents(rents, SIZE) << endl;
		}
		else if (choice == 5) {
			cout << "\n";
			displayMemoryLocations(rents, SIZE);
		}
		else {
			cout << "\nInvalid menu choice. Please select menu option 1-6." << endl;
			
		}choice = getMenuItem();
	}
	system("pause");
	return 0;
}

