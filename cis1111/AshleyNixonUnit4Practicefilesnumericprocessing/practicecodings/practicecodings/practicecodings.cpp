// practicecodings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	int count = 0;
	double number, sumNumbers = 0, averageNumbers;

	//open the file for input
	ifstream inputFile;
	inputFile.open("datafile.txt");

		//do not process if file doesn't exist.
	if (inputFile)
	{
		//read each number and assign it to the number
		while (inputFile >> number)
		{
			sumNumbers += number;
			count += 1;
		}
		averageNumbers = sumNumbers / count; //calculating the average

		//display results
		cout << "Numbers processed:" << count << "\n" << endl;
		cout << "The total of the numbers: " << sumNumbers << "\n" << endl;
		cout << fixed << setprecision(2);
		cout << "The average of the numbers: " << averageNumbers << "\n" << endl;
	}
	else
		cout << "Error opening file." << endl << endl;

	system("pause");
	return 0;
}
