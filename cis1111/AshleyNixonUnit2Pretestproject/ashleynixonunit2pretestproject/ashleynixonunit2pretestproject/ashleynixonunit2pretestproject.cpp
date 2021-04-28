//Ashley Nixon
//January 16, 2019
//Catering Cost Calulator
//CIS 1111 Programming Assignment Unit 2 -- Expressions: In this program you are going to design a program to calculate the cost to cater a dinner.

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>


using namespace std;

int main()
{
	string custName;
	string eventName;
	const double COST_PER_HOUR = 15.00; //Servers make $15 per hour
	const double COST_PER_MIN = 0.50; //Servers make .50c per minute over an hour
	const double COST_OF_DINNER = 31.80; //Each dinner costs $31.80

	double numOfGuests;
	int eventDurationMins;
	
	int hours = 0;
	int minutes = 0;

	//Get user data! +++++++++++++++++++++++++++++++++++++++++++


	cout << "Enter customer's first and last name: "; //User enters their name, or the client's name.
	getline(cin, custName, '\n');

	cout << "Enter event name: "; //User enters event name.
	getline(cin, eventName, '\n');

	cout << "Enter number of guests expected:"; //User enters number of guests. This needs to be a whole number.
	cin >> numOfGuests;

	cout << "Enter number of minutes for the event (note 1 hour=60 minutes):"; //number of minutes for the event to be entered, with note of reminder that prompts user to use minutes with reminder to convert hours to minutes.
	cin >> eventDurationMins;
	
	//Do the math. +++++++++++++++++++++++++++++++

	double totalCost = numOfGuests * COST_OF_DINNER; //Base food cost calculation
	double numOfServers = ceil(numOfGuests / 15); //server numbers
	double eventHours = eventDurationMins / 60; //event minutes
	double eventMin = eventDurationMins % 60; //event hours
	double costPerServer = (eventHours * COST_PER_HOUR) + (eventMin * COST_PER_MIN); //Base server costs
	double totalServerCost = costPerServer * numOfServers; //total server costs
	double eventCost = totalCost + totalServerCost; //event total cost
	double costPerPerson = eventCost / numOfGuests; //Average cost per guest

	//Print the invoice. +++++++++++++++++++++++++++

	cout << "\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
	
	cout << "\n" << eventName << endl;
	cout << custName << endl;

	cout << "\nNumber of Servers: " << numOfServers << endl;
	cout << setprecision(2) << fixed;
	cout << left << setw(25) << "Total cost of servers: " << "$" << setw(10) << right << totalServerCost << endl;
	cout << left << setw(25) << "Total cost for food: " << "$" << setw(10) << right << totalCost << endl;
	cout << left << setw(25) << "Average cost per person: " << "$" << setw(10) << right << costPerPerson << endl;
	cout << left << setw(25) << "Total event cost: " << "$" << setw(10) << right << eventCost << endl;

	cout << left << setw(25) << "\nPlease provide a 25% deposit to reserve the event " << fixed << setprecision(2) << setw(10) << right << endl;
	cout << left << setw(25) << "The deposit is: " << "$" << setw(10) << right << eventCost * 25 / 100 << endl;

	system("pause");
	return 0;
}