/* 
 Ashley Nixon
 07/03/2019
 Uber Driver Program
 a menu-drive program that allows a user to show Uber Driver Requirements, Uber Vehicle Requirements, 
 as well as take a test to see if the User Qualifies to be an Uber Driver.
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "UberVehicle.h"
#include "UberDriver.h"

using namespace std;

//constatns for formatted output
#define COLUMN1_WIDTH 55
#define COLUMN2_WIDTH 15

//function implementations

/*
showMenu();
	i. Displays the menu
		menu
		a. Display Uber Vehicle Requirements
		b. Display Uber Driver Requirements
		c. See if you Qualify to be a driver
		d. Exit the program
	ii. Inputs the user's selection
	iii. Validates the user's selection
*/

int showMenu() {
	int userEntry = 0;
	bool badEntry = true;

	cout << endl << " * * * * M A I N   M E N U * * * * * * *" << endl << endl;
	cout << "1. Enter Uber Vehicle Requirements" << endl;
	cout << "2. Enter Uber Driver Requirements" << endl;
	cout << "3. See if you Qualify to be a driver" << endl;
	cout << "4. Exit the program" << endl << endl;

		do {
			cout << "Enter your choice (1-4): ";
			cin >> userEntry;

			badEntry = cin.fail() || userEntry < 1 || userEntry >4;
			
			if (cin.fail()) {
				cin.clear();
			}
			cin.ignore(100, '\n'); //clear all line from cin
		} while (badEntry);

		return userEntry;
}

//utility funcition for printing Uber Vehicle object in formatted manner
void displayUberVehicle (UberVehicle vehicle) {
	cout << setw(COLUMN1_WIDTH) << left << "| Vehicle Number of Doors:"
		<< setw(COLUMN2_WIDTH) << vehicle.Get_vehicleNumberOfDoors() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Vehicle Year:"
		<< setw(COLUMN2_WIDTH) << vehicle.Get_vehicleYear() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Vehicle Make:"
		<< setw(COLUMN2_WIDTH) << vehicle.Get_vehicleMake() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Vehicle Model:"
		<< setw(COLUMN2_WIDTH) << vehicle.Get_vehicleModel() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Does Vehicle have in state license plates:"
		<< setw(COLUMN2_WIDTH) << vehicle.Get_inStateVehiclePlates() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Is the vehicle marked Taxi or Salvage:"
		<< setw(COLUMN2_WIDTH) << vehicle.Get_isVehicleMarketTaxiOrSalvage() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Has vehicle passed Uber inspection:"
		<< setw(COLUMN2_WIDTH) << vehicle.Get_hasVehiclePassedInspection() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Is the vehicle currently registered:"
		<< setw(COLUMN2_WIDTH) << vehicle.Get_isVehicleRegistered() << "|" << endl;
}

//utility function for printing Uber Driver object in formatted manner.
void displayUberDriver (UberDriver driver) {
	cout << setw(COLUMN1_WIDTH) << left << "| Minimum Age of Driver:"
		<< setw(COLUMN2_WIDTH) << driver.Get_ageOfDriver() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Years of Driving Experience:"
		<< setw(COLUMN2_WIDTH) << driver.Get_yearsOfDrivingExperiance() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Is Vehicle Ensured to the Driver:"
		<< setw(COLUMN2_WIDTH) << driver.Get_isVehicleEnsuredToDriver() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Has background been Cleared:"
		<< setw(COLUMN2_WIDTH) << driver.Get_isBackgroundCheckClear() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Has Driver Record been Cleared:"
		<< setw(COLUMN2_WIDTH) << driver.Get_isDriverRecordClear() << "|" << endl;
	cout << setw(COLUMN1_WIDTH) << left << "| Does Driver have a Smart Phone:"
		<< setw(COLUMN2_WIDTH) << driver.Get_driverHasSmartPhone() << "|" << endl;
}

/*
showUberVehicleRequirements();
	i. creates an instance of the Uber Vehicle class and makes a call to an overloaded constructor to initialize the object with Uber's Vehicle Requirements
	ie: UberVehicle UberVehicle(4,2001,"Toyota","Camery","Yes","No","Yes","Yes");
*/
void showUberVehicleRequirements() {
	UberVehicle uberVehicle(4, 2001, "Toyota", "Camery", "Yes", "No", "Yes", "Yes");
	//show table header
	cout << string(COLUMN1_WIDTH + COLUMN2_WIDTH + 1, '-') << endl;
	cout << "|                Uber Vehicle Requirements                            |" << endl;
	cout << string(COLUMN1_WIDTH + COLUMN2_WIDTH + 1, '-') << endl;

	//show the created vehicle in tabular form
	displayUberVehicle(uberVehicle);

	cout << string(COLUMN1_WIDTH + COLUMN2_WIDTH + 1, '-') << endl;

}

/*
showUberDriverRequirements();
	i. creates an instance of the Uber Driver class and makes a call to an overloaded constructor to initialize the object with Uber's Driver Requirements
	ie: UberDriver UberDriver(21,3,"Yes", "Yes", "Yes", "Yes");
*/
void showUberDriverRequirements() {
	UberDriver uberDriver(21, 3, "Yes", "Yes", "Yes", "Yes");
	//show table header
	cout << string(COLUMN1_WIDTH + COLUMN2_WIDTH + 1, '-') << endl;
	cout << "|                Uber Driver Requirements                             |" << endl;
	cout << string(COLUMN1_WIDTH + COLUMN2_WIDTH + 1, '-') << endl;

	//show the created driver in tabular form
	displayUberDriver(uberDriver);

	cout << string(COLUMN1_WIDTH + COLUMN2_WIDTH + 1, '-') << endl;

}

//utility function for yes/no entry
string getYesNo() {
	string userEntry;

	cin >> userEntry;
	while (userEntry != "Yes" && userEntry != "No") {
		cout << "(Enter Yes/No):" << endl;
		cin >> userEntry;
	}
	return userEntry;
}

/*
displayUsersData(UberDriver,UberVehicle);
	i. method should be called and passed two arguments UberDriver and UberVehicle. Both of these objects should hold user's data from the previous method.
	ii. displays User's answers neatly formatted
*/
void displayUsersData(UberDriver driver, UberVehicle vehicle) {
	cout << string(COLUMN1_WIDTH + COLUMN2_WIDTH + 1, '-') << endl;
	cout << "|                User's Application Data                              |" << endl;
	cout << string(COLUMN1_WIDTH + COLUMN2_WIDTH + 1, '-') << endl;
	cout << setw(COLUMN1_WIDTH - 2) << left << "|                Questions"
		<< setw(COLUMN2_WIDTH) << "| User's Answer" << "  |" << endl;
	cout << string(COLUMN1_WIDTH + COLUMN2_WIDTH + 1, '-') << endl;
	cout << "|" << string(COLUMN1_WIDTH + COLUMN2_WIDTH - 1, ' ') << "|" << endl;

	//show driver in tabular form
	displayUberDriver(driver);

	cout << "|" << string(COLUMN1_WIDTH + COLUMN2_WIDTH - 1, ' ') << "|" << endl;
	//show the vehicle in tabular form
	displayUberVehicle(vehicle);

	//table bottom line
	cout << string(COLUMN1_WIDTH + COLUMN2_WIDTH + 1, '-') << endl;
}

/*
setUserData();
	i. creates an instance of both the Uber Driver and Vehicle class, then asks a series of questions to set the object's mutators (setters) with approprate values
	ii. Make sure to validate user's input
*/
void setUserData() {
	int ageOfDriver;
	int yearsOfDrivingExperiance;
	int vehicleNumberOfDoors;
	int vehicleYear;
	string vehicleMake;
	string vehicleModel;
	UberVehicle uberVehicle;
	UberDriver uberDriver;

	cout << endl;
	cout << "Let's See if you Qualify to be a driver. Answer Each question to see if you Qualify to be an Uber Driver:" << endl;

	//initialize uber driver information
	cout << endl << "Please Enter Your Current Age:" << endl;
	cin >> ageOfDriver;
	uberDriver.Set_ageOfDriver(ageOfDriver);

	cout << endl << "Please Enter Your Years of Driving Experience:" << endl;
	cin >> yearsOfDrivingExperiance;
	uberDriver.Set_yearsOfDrivingExperiance(yearsOfDrivingExperiance);

	cout << endl << "Is Vehicle Ensured to the Driver (Enter Yes/No):" << endl;
	uberDriver.Set_isVehicleEnsuredToDriver(getYesNo());

	cout << endl << "Can the Driver Pass a Background Check (Enter Yes/No):" << endl;
	uberDriver.Set_isBackgroundCheckClear(getYesNo());

	cout << endl << "Does the driver have a clear Driving Record (Enter Yes/No):" << endl;
	uberDriver.Set_isDriverRecordClear(getYesNo());

	cout << endl << "Does the driver have a Smart Phone (Enter Yes/No):" << endl;
	uberDriver.Set_diverHasSmartPhone(getYesNo());

	//initialize Uber vehicle information
	cout << endl << "Please Enter Your Vehicle's Make:" << endl;
	cin >> vehicleMake;
	uberVehicle.Set_vehicleMake(vehicleMake);

	cout << endl << "Please Enter Your Vehicle's Model:" << endl;
	cin >> vehicleModel;
	uberVehicle.Set_vehicleModel(vehicleModel);
	
	cout << endl << "Please Enter Your Vehicle's Year:" << endl;
	cin >> vehicleYear;
	uberVehicle.Set_vehicleYear(vehicleYear);

	cout << endl << "Please Enter Your Vehicle's Number of Doors" << endl;
	cin >> vehicleNumberOfDoors;
	uberVehicle.Set_vehicleNumberOfDoors(vehicleNumberOfDoors);

	cout << endl << "Does Vehicle have in state license plates (Enter Yes/No):" << endl;
	uberVehicle.Set_inStateVehiclePlates(getYesNo());

	cout << endl << "Is the vehicle marked Taxi or Salvage (Enter Yes/No):" << endl;
	uberVehicle.Set_isVehicleMarketTaxiOrSalvage(getYesNo());

	cout << endl << "Has vehicle passed Uber inspection (Enter Yes/No):" << endl;
	uberVehicle.Set_hasVehiclePassedInspection(getYesNo());

	cout << endl << "Is the vehicle currently registered (Enter Yes/No):" << endl;
	uberVehicle.Set_isVehicleRegistered(getYesNo());

	//display user answers
	displayUsersData(uberDriver, uberVehicle);

}

/*
	Main program uses a while loop with embedded switch statements to call appropriate functions based on menu choice.
*/

int main() {
	int menuEntry;

	do {
		menuEntry = showMenu();

		switch (menuEntry) {
			case 1:
				//showCurrent Uber Vehicle Requirements
				showUberVehicleRequirements();
				break;
			case 2:
				//show Current Uber Driver Requirements
				showUberDriverRequirements();
				break;
			case 3:
				//Fill and display users application form
				setUserData();
				break;
			default:
				break;
		}
	} while (menuEntry != 4);
	return 0;
}