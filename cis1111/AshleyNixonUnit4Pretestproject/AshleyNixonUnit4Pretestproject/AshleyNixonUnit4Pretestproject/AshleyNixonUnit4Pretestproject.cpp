//Ashley Nixon
//02-24-2019
//Property Management Rent Collection Records
//Program will will calculate total rent collected for the company, average rent collected per month for the company, display the highest grossing complex, and displays a warning message if zero rent was entered for any of the complexes. 

#include "pch.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
		double months, incomeMain, incomeClay, incomeKing; //income
		double averageRent, highRent, highestRent, allAverage;
		int numMonths, choice; //number of months for recorded rent
		const int COMPLEX_MAIN = 1,
			COMPLEX_CLAY = 2,
			COMPLEX_KING = 3,
			COMPLEX_NEXT = 4;

		//get the number of months
		cout << fixed << showpoint << setprecision(2);
		cout << "Enter the number of months rent: ";
		cin >> numMonths;
		
		//open and create the file for each apartment complex. mainRent, clayRent, kingRent
		ofstream mainRent;
		mainRent.open("mainRent.txt");
		ofstream clayRent;
		clayRent.open("clayRent.txt");
		ofstream kingRent;
		kingRent.open("kingRent.txt");

		for (;;)
		{
		//cycle through Main, Clay, King
		cout << "Which Complex rent are you entering?\n"
			<< "Enter 1 for Complex Main.\n"
			<< "Enter 2 for Complex Clay.\n"
			<< "Enter 3 for Complex King.\n"
			<< "Enter 4 to Continue.\n";
			cin >> (choice);

			switch (choice)
			{
				//get the rent for each month and write it
				//go to the file

			case COMPLEX_MAIN:
				for (int count = 1; count <= numMonths; count++)
					{
						//get the rent for a month.
						cout << "Enter the rent for Main, month "
							<< count << ": ";
						cin >> incomeMain;

						//write the rent to the file.
						mainRent << incomeMain << endl;
					}
					continue;
			case COMPLEX_CLAY:
				for (int count = 1; count <= numMonths; count++)
				{
					cout << "Enter rent for Clay, month "
						<< count << ": ";
					cin >> incomeClay;

					clayRent << incomeClay << endl;
				}
				continue;
			case COMPLEX_KING:
				for (int count = 1; count <= numMonths; count++)
				{
					cout << "Enter rent for King, month"
						<< count << ": ";
					cin >> incomeKing;

					kingRent << incomeKing << endl;
				}
				continue;

			case COMPLEX_NEXT:
				
				cout << "Data written to Rent.txt\n";

				break;
				}
				break;
			}

		//close the file
		mainRent.close();
		clayRent.close();
		kingRent.close();

		//open files to read
		ifstream mainRead;
		double main1, main2, main3, main4, main5;
		mainRead.open("mainRent.txt");

		ifstream clayRead;
		double clay1, clay2, clay3, clay4, clay5;
		clayRead.open("clayRent.txt");

		ifstream kingRead;
		double king1, king2, king3, king4, king5;
		kingRead.open("kingRent.txt");

		//read each month file
		mainRead >> main1;
		mainRead >> main2;
		mainRead >> main3;
		mainRead >> main4;
		mainRead >> main5;
		clayRead >> clay1;
		clayRead >> clay2;
		clayRead >> clay3;
		clayRead >> clay4;
		clayRead >> clay5;
		kingRead >> king1;
		kingRead >> king2;
		kingRead >> king3;
		kingRead >> king4;
		kingRead >> king5;

		cout << fixed;
		cout << setprecision(0);
		cout << "\nComplex Main: " << main1 << " " << main2 << " " << main3 << " " << main4 << " " << main5 << endl;
		cout << "\nComplex Clay: " << clay1 << " " << clay2 << " " << clay3 << " " << clay4 << " " << clay5 << endl;
		cout << "\nComplex King: " << king1 << " " << king2 << " " << king3 << " " << king4 << " " << king5 << endl;
		
		//do math
		//add up for total rent collected.
		double totalMainRent = main1 + main2 + main3 + main4 + main5;
		double totalClayRent = clay1 + clay2 + clay3 + clay4 + clay5;
		double totalKingRent = king1 + king2 + king3 + king4 + king5;
		double totalRent = totalMainRent + totalClayRent + totalKingRent;
		
		cout << "\nTotal rent collected for the company = $" << totalRent << endl;

		// total rent/ nummonths for average rent
		averageRent = totalRent / numMonths;

		cout << "\nAverage monthly rent collected for the company = $" << averageRent << endl;

		
		//print who collected most rent
		if (totalMainRent > totalClayRent && totalMainRent > totalKingRent)
			cout << "\nComplex Main collected the most rent. $" << totalMainRent << " was collected." << endl;
		else if (totalClayRent > totalMainRent && totalClayRent > totalKingRent)
			cout << "\nComplex Clay collected the most rent. $" << totalClayRent << " was collected." << endl;
		else if (totalKingRent > totalMainRent && totalKingRent > totalClayRent)
			cout << "\nComplex King collected the most rent. $" << totalKingRent << " was collected." << endl;
		else
			cout << "\nInvalid data supplied." << endl;
		//warn a complex had 0 for month rent
		if ((main1 == 0) || (main2 == 0) || (main3 == 0) || (main4 == 0) || (main5 == 0) || (clay1 == 0) || (clay2 == 0) || (clay3 == 0) || (clay4 == 0) || (clay5 == 0) || (king1 == 0) || (king2 == 0) || (king3 == 0) || (king4 == 0) || (king5 == 0))
			cout << "\n\nWarning! One of the complexes submitted zero rent for one of the months.\n" << endl;
		//close read files
		mainRead.close();
		clayRead.close();
		kingRead.close();


		
	    system("PAUSE");
	    return 0;
}
