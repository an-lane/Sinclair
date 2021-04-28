//Ashley Nixon
//01-21-2019
//Soil Test Kit
//Program that provides the corrective action for a customer's lawn given the soil sample. Must be password protected

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
 //password protected with "password"
	string password;
	cout << "Please enter your password, if incorrect the program will terminate: (password) \n";
	getline(cin, password);

	if (password == "password")
	{
		//Contants and Variables

		int choice;
		double phData, nitrogenData, phosphorusData, potassiumData;

		const int PH_SELECT = 1,
			NITROGEN_SELECT = 2,
			PHOSPHORUS_SELECT = 3,
			POTASSIUM_SELECT = 4;

		//Menu with choices, request user input for choices

		cout << "What soil tests results are you entering?\n\n"
			<< "Enter 1 for pH\n"
			<< "Enter 2 for Nitrogen\n"
			<< "Enter 3 for Phosphorus\n"
			<< "Enter 4 for Potassium\n"
			<< "Enter any other number to terminate the program.\n";
			cin >> (choice);
		 
			switch (choice)
			{
			//pH data output
            case PH_SELECT:
				cout << "Enter the result of the PH test: \n";
				cin >> phData;
				if (phData > 0 && phData < 5.5)
					cout << "The soil pH level is low.\n";
				else if (phData >= 5.5 && phData <= 7)
					cout << "The soil pH level is normal.\n";
				else if (phData > 7 && phData <= 14)
					cout << "The soil pH level is too alkaline.\n";
				else
					cout << "You did not enter a number within range of 0-14.\n";
				break;
				//Nitrogen data output
			case NITROGEN_SELECT:
				cout << "Enter the result of the Nitrogen test: \n";
				cin >> nitrogenData;
				if (nitrogenData > 0 && nitrogenData < 10)
					cout << "The soil Nitrogen level is low.\n";
				else if (nitrogenData >= 10 && nitrogenData <= 20)
					cout << "The soil Nitrogen level is medium.\n";
				else if (nitrogenData > 20 && nitrogenData <= 30)
					cout << "The soil Nitrogen level is high.\n";
				else if (nitrogenData > 30)
					cout << "The soil Nitrogen level is excessive.\n";
				else
					cout << "You did not enter a valid test result.\n";
				break;
				//Phosphorus data output
			case PHOSPHORUS_SELECT:
				cout << "Enter the data of the Phosphorus test: \n";
				cin >> phosphorusData;
				if (phosphorusData > 0 && phosphorusData < 20)
					cout << "The soil Phosphorus level is low.\n";
				else if (phosphorusData >= 20 && phosphorusData <= 40)
					cout << "The soil Phosphorus level is medium.\n";
				else if (phosphorusData > 40 && phosphorusData <= 100)
					cout << "The soil Phosphorus level is high.\n";
				else if (phosphorusData > 100)
					cout << "The soil Phosphorus level is excessive.\n";
				else
					cout << "You did not enter a valid test result.\n";
				break;
				//Potassium data output
			case POTASSIUM_SELECT:
				cout << "Enter the data of the Potassium test: \n";
				cin >> potassiumData;
				if (potassiumData > 0 && potassiumData < 70)
					cout << "The soil Potassium level is very low.\n";
				else if (potassiumData >= 70 && potassiumData <= 150)
					cout << "The soil Potassium level is low.\n";
				else if (potassiumData > 150 && potassiumData <= 250)
					cout << "The soil Potassium level is medium.\n";
				else if (potassiumData > 250 && potassiumData <= 800)
					cout << "The soil Potassium level is high.\n";
				else if (potassiumData > 800)
					cout << "The soil Potassium level is very high.\n";
				else
					cout << "You did not enter a valid test result.\n";
				break;
		    }
	}
    // Bad/failed password entry
	else return 0;
	
	system("pause");

	return 0;
}