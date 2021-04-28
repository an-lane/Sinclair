// Ashley Nixon
//CIS 1111 : Unit 6 Arrays and Vectors Pre-test project
//National Parks 2D Arrays
// C++ program to calculate and analyze the data from the number of visitors to a national park in Maine.

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//main program
int main()
{
	//Declaring variables including constants for columns, 12 months and 9 columns.
	const int mon = 12, col = 9;
	int i = 0, choice;
	string months[mon], nameMonth;
	int val;
	int visitors[mon][col];

	//defines an input stream for the data file
	ifstream readData;

	//Opening the input file
	readData.open("Months.txt");

	//check for valid file.
	if (readData.fail()) 
	{

		cout << "**Months.txt File Not Found **" << endl;

		return 1;

	}
	
	else 
	{

		//Reading the data from the file
		while (readData >> nameMonth) 
		{

			months[i] = nameMonth;
			i++;

		}

		//close file
		readData.close();

		//Opening the input file
		readData.open("AcadiaVisitors.txt");

		if (readData.fail()) 
		{

			cout << "**AcadiaVisitors.txt File Not Found **" << endl;
			return 1;

		}
	
		else 
		{

			//Reading the data from the file
			for (i = 0; i < mon; i++) 
			{

				for (int j = 0; j < col; j++) 
				{

				readData >> val;
				visitors[i][j] = val;

				}

			}
			
			//close file
			readData.close();

			// while loop to repeat until proper selection made or 5 is selected to terminate the data.

			while (true) 
			{

				//displaying the menu
				cout << "\nVistors to Acadia National Park" << endl;

				cout << "1 Display the data" << endl;

				cout << "2 Total Visitors number of recreation and non-recreational visitors" << endl;

				cout << "3 Total tent and RV campers by month" << endl;

				cout << "4 Display the number of rereational visitors for a certain month" << endl;

				cout << "5 Exit" << endl;

				//getting the choice entered by the user
				cout << "\nEnter your option number: ";
				cin >> choice;

				//User entered data will display which case

				switch (choice) 
				{

					case 1:
					{

						cout << "Month\t\tT Rec\tT Non-Rec   Con lodging\tTent\t RV\tCon Camp  BackCountry\tMisc Camp  T Overnite" << endl;

						for (int i = 0; i < mon; i++) //builds table months in a column
						{

							cout << setw(10) << left << months[i];

							for (int j = 0; j < col; j++) //reads and builds columsn for the data.
							{

								cout << setw(10) << right << visitors[i][j]; 

							}

							cout << endl;

						}

						continue;

					}

					//case 2 displays total amount of recreational and non recreational visitors
					case 2:
					{

						int recVisTot = 0;
						int nonrecVisTot = 0;

						for (int i = 0; i < mon; i++) 
						{						

								recVisTot += visitors[i][0];
								nonrecVisTot += visitors[i][1];

						}

						cout << "\nTotal number of recreational and non-recreational visitors: " << recVisTot + nonrecVisTot << endl;
						continue;

					}
					
					//**** total tent and RV campers by month col 3 col 4******
					case 3:
					{

						int totTent = 0;
						int totRV = 0;

						cout << "\nTotal Tent and RV campers by Month\n" << endl;
						
						for (int i = 0; i < mon; i++) //reading the month
						{

							totTent = 0;
							totRV = 0;

							cout << setw(10) << left << months[i];

								totTent += visitors[i][3];
								totRV += visitors[i][4];

							cout << setw(10) << right << totTent + totRV << endl;

						}

						continue;

					}
					
					//recreational visitors displayed by month. User chooses month 1 12, displays data for month by column 0
					case 4:
					{
						int numMonth;
						cout << "\nEnter the Month to display by number (1-12): ";
						cin >> numMonth;//user will define the month by number
						//nested switch for each month
						switch (numMonth)
						{
							//month 1
						case 1:
							//January
							cout << "\nJanuary visitors: " << visitors[0][0] << endl;
							break;
						case 2:
							//Feburary
							cout << "\nFeburary visitors: " << visitors[1][0] << endl;
							break;
						case 3:
							//March
							cout << "\nMarch visitors: " << visitors[2][0] << endl;
							break;
						case 4:
							//April
							cout << "\nApril visitors: " << visitors[3][0] << endl;
							break;
						case 5:
							//May
							cout << "\nMay visitors: " << visitors[4][0] << endl;
							break;
						case 6:
							//June
							cout << "\nJune visitors: " << visitors[5][0] << endl;
							break;
						case 7:
							//July
							cout << "\nJuly visitors: " << visitors[6][0] << endl;
							break;
						case 8: 
							//August
							cout << "\nAugust visitors: " << visitors[7][0] << endl;
							break;
						case 9:
							//September
							cout << "\nSeptember visitors: " << visitors[8][0] << endl;
							break;
						case 10:
							//October
							cout << "\nOctober visitors: " << visitors[9][0] << endl;
							break;
						case 11:
							//November
							cout << "\nNovember visitors: " << visitors[10][0] << endl;
							break;
						case 12:
							//December
							cout << "\nDecember visitors: " << visitors[11][0] << endl;
							break;

						default:
							//when another choice is entered that is not valid, will bring back to selection menu.
							cout << "\nChoice is invalid. Please chose Month by number (1-12)." << endl;
							
						}

						continue;

					}

					case 5:
					{

						break;

					}
				}
				break;
			}
		}
	}
	system("pause");
	return 0;
}