/*
Ashley Nixon
07/19/2019
Final Project
Calorie Tracker
Utilizing user input record and track meals for user, can be whole or decimals, must not be negative numbers.
*/
#include "pch.h"
#include "head.h"
#include "Meal.h"

int UserInputInt()
{
	double choice = 0;
	string str; // string for checking exceptions
	while (cout << ">> ", cin >> str) { // reading user input in string  
		try {
			choice = stod(str); // try convert string to double
			if (choice == int(choice)) {
				return (int)choice;
				break;
			}
			else {
				cout << "Input must be an integer" << endl;
			}
		}
		catch (exception) { // if convert return exception
			cout << "Incorrect input, try again" << endl;
		}
	}
}

void printMenu() {
	cout << endl << "<Main Menu>" << endl;
	cout << "1.  Display Daily Summary" << endl;
	cout << "2.  Display Detailed Daily Record" << endl;
	cout << "3.  Add Food to Meal" << endl;
	cout << "4.  Delete Food from Meal" << endl;
	cout << "5.  Change Target" << endl;
	cout << "6.  Exit" << endl;
}

void printAllDayRation(Meal dayRation[], const int n, double target)
{
	double totalSum = 0;
	for (int i = 0; i < n; i++) {
		dayRation[i].display();
		totalSum += dayRation[i].totalCalories();
	}
	cout << "\t|| TOTAL DAY CALORIES = " << totalSum << endl;
	cout << "\t|| TARGET CALORIES = " << target << endl;
	if (target < totalSum) {
		cout << "Warning, you have excess calories = " << totalSum - target << endl;
	}
	cout << "------------------------------------------" << endl;
}

void printBriefDayRation(Meal dayRation[], const int n, double target) {
	double totalSum = 0;
	for (int i = 0; i < n; i++) {
		cout << dayRation[i].getName() << " : " << dayRation[i].totalCalories() << " cal" << endl;
		totalSum += dayRation[i].totalCalories();
	}
	cout << "------------------------------------------------ " << endl;
	cout << "\t|| TOTAL DAY CALORIES = " << totalSum << endl;
	cout << "\t|| TARGET CALORIES = " << target << endl;
	if (target < totalSum) {
		cout << "Warning, you have excess calories = " << totalSum - target << endl;
	}
	cout << "------------------------------------------" << endl;
}

void addMenu(Meal dayRation[], const int n)
{
	cout << endl << "<Add Menu>" << endl;
	cout << "Choose Meal: " << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ".  " << dayRation[i].getName() << endl;
	}
	cout << n + 1 << ".  EXIT" << endl; // exit option
	int choice;

	choice = UserInputInt();

	while (choice <= n + 1 && choice > 0) {

		if (choice == n + 1) { // exit 
			return; // quit from func
		}
		else if (choice < n + 1 && choice > 0) {
			addFoodMenu(dayRation[choice - 1]);
			break;
		}
		else {
			cout << "Unknown Choice, Try Again" << endl;
			choice = UserInputInt();
		}
	}

}

void addFoodMenu(Meal & meal)
{
	int choice = 0;
	cout << "Choose type:" << endl;
	cout << "1.  Food \n2.  Drink" << endl;

	choice = UserInputInt();

	while (choice != 1 && choice != 2) {
		cout << "Unknown Choice, Try Again" << endl;
		choice = UserInputInt();

	}

	int count = 1; // default count of food
	Meal::type typ;
	string name;
	double p = 0, c = 0, f = 0;

	if (choice == 1) {
		typ = Meal::FOOD;
	}
	else {
		typ = Meal::BEVERAGE;
	}
	cin.ignore();

	cout << "Please enter the name of the ";
	if (typ == Meal::FOOD) cout << "food: ";
	else cout << "drink: ";

	getline(cin, name);

	cout << "How much fat is in " << name << ": ";
	cin >> f;
	cout << "How much protein is in " << name << ": ";
	cin >> p;
	cout << "How many carbohydrates are in " << name << ": ";
	cin >> c;
	cout << "How many " << name << " (1, 2, 3, ...): ";
	cin >> count;

	Food * ptr = new Food(name, f, p, c);
	meal.add(*ptr, typ, count);

}

void delMenu(Meal dayRation[], const int n)
{
	cout << endl << "<Del Menu>" << endl;
	cout << "Choose the meal you want to delete a food from: " << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ".  " << dayRation[i].getName() << endl;
	}
	cout << n + 1 << ".  EXIT" << endl; // exit option
	int choice;
	choice = UserInputInt();

	while (choice <= n + 1 && choice > 0) {

		if (choice == n + 1) { // exit 
			return; // quit from func
		}
		else if (choice < n + 1 && choice > 0) {
			delFoodMenu(dayRation[choice - 1]);
			break;
		}
		else {
			cout << "Unknown Choice, Try Again" << endl;
			choice = UserInputInt();
		}
	}
}

void delFoodMenu(Meal& meal)
{
	cout << endl << "<Delete Menu of " << meal.getName() << " >" << endl;
	meal.display();

	string buff;
	cin.get();
	cout << "Enter food or drink to delete: ";
	getline(cin, buff);
	meal.del(buff);
}
