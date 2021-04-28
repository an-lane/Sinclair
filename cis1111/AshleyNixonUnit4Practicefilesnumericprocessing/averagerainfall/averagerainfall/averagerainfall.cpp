// averagerainfall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//number of years to calculate the average rainfall. Months is years * 12
	int years, totalMonths;
	double rainFall, totalInches = 0, avgInches; 

	//enter number of years and verify greater than or equal to one year.
	cout << "Enter the number of years ";
	cin >> years;
	while (years < 1)
	{
		cout << "Please enter a number of years that is 1 or more";
		cin >> years;
	}

	//beginning nested loop
	for (int i = 0; i < years; i++)
		//outerloop
	{
		for (int j = 0; j < 12; j++)
			//inner loop runs 12 months

		{
			cout << "Enter the rainfall for month " << j + 1 << " "; //rainfall for each month
			cin >> rainFall;
			while (rainFall < 0) //rainfall may not go below 0

			{
				cout << "Enter the rainfall for month 0 or greater" << j + 1 << " ";
				cin >> rainFall;
			}

			totalInches = totalInches + rainFall;

		}
		cout << "\n";
		//sepearte new lines
		cout << "Enter rainfall for year " << i + 2 << endl;

	}
	//all data gathered now just calculate!
	totalMonths = years * 12;
	avgInches = totalInches / totalMonths;
	cout << "The average is " << avgInches << endl;

	system("pause");
	return 0;
}
