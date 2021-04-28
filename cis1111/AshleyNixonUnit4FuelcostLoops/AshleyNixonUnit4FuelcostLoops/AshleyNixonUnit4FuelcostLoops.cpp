//Ashley Nixon
//02-05-2019
//Fuel Cost 
//Accumulate and average fuel prices with esitmations on how much it costs to drive your car one mile. 

#include "pch.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int i = 0, beginOdo = 0, endOdo = 1, sumOdo = 0, gal, sumGal = 0;
	float fuelPrice, sumFuelPrice = 0, avgFuelPrice, milesPerGal;
	char cont;

	//open files for data entry
	ofstream gallonsFile;
	gallonsFile.open("sumgallons.txt");
	ofstream odoFile;
	odoFile.open("sumodo.txt");

	while (1)
	{
		cout << "Enter the beginning odometer reading: "; //taking beginning odometer reading
		cin >> beginOdo;
		if (beginOdo < endOdo && i > 0)
		{
			cout << "Beginning odometer reading must be greater than Ending odometer reading. ";
				return 0;
		}

		cout << "Enter the ending odometer reading: "; //taking ending odometer reading
		cin >> endOdo;
		if (endOdo <= beginOdo)
		{
			cout << "Ending odometer reading must be greater than beginning odometer reading. ";
			return 0;
		}

		sumOdo += endOdo - beginOdo; //miles driven calculated

		odoFile << sumOdo << " "; //enter sumOdo into file for data

		cout << "Enter the gallons required for fill-up: "; //galons for fillup
		cin >> gal;
		if (gal < 1)
		{
			cout << "\nGallons must be greater than 0";
			return 0;
		}

		sumGal += gal; //gallons

		//enter sumGal into file for data
		gallonsFile << sumGal << " ";

		cout << "Enter y to enter another trip data, n to enter fuel prices. "; //re loop or move on
		cin >> cont;
		if (cont != 'y')
			break;
		i++;
	}

	for (i = 0; i < 3; i++) //station number and advancing
	{
		cout << "Enter the price per gallon at station #" << i + 1 << ": ";
		cin >> fuelPrice;
		
		if (fuelPrice < 1)
		{
			cout << "\nPrice for fuel must be greater than 0";
			return 0;
		}
		sumFuelPrice += fuelPrice; //fuel price sum
	}
	
	//close txt data files.
	gallonsFile.close();
	odoFile.close();
	
	cout << fixed;
	cout << setprecision(2);

	avgFuelPrice = sumFuelPrice / 3; //average fuel price

	//open input files
	ifstream odoRead;
	float sumOdometer;
	odoRead.open("sumodo.txt");

	ifstream gallRead;
	float sumGallons;
	gallRead.open("sumgallons.txt");

		//read from files
		gallRead >> sumGallons;
	odoRead >> sumOdometer;

	milesPerGal = sumOdometer / sumGallons;

	//calculate and print milesPerGal

	 
	cout << "Your cars average mile per gallon is: " << milesPerGal;
	cout << "\nYou bought gas at an average of $" << avgFuelPrice << " per gal.";
	cout << "\nThe cost per mile for your car is: " << avgFuelPrice / milesPerGal;

	if (milesPerGal <= 25 && milesPerGal >= 0)
		cout << "\nYour car is ineffecient\n";
	else if (milesPerGal <= 30 && milesPerGal >= 16)
		cout << "\nYour car is ok\n";
	else if (milesPerGal >= 31)
		cout << "\nYour car is highly effecient!\n";
	else
		cout << "\nInvalid data supplied.\n";

	//close txt data files.
	gallRead.close();
	odoRead.close();
	system("pause"); //close system
	return 0;
 }
