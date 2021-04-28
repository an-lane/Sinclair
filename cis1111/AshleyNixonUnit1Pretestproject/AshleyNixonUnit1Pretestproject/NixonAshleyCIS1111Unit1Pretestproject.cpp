//Ashley Nixon
//January 9, 2019
//Computer and Tablet Replacement Quote
//CIS 1111 Programming Assignment-- Basic Math, a C++ program that calulates the cost to replace all tablets and desktop computers in a business.

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	//Get input about company and needs ++++++++++++++++++++++++++++++++++++++++++
	double  tablets = 0; 
	double computers = 0;
	std::string companyname = "";

	cout << "Enter the name of the company: " << endl;
	    getline(cin, companyname, '\n');
	    cin.clear();

	cout << "Enter the number of tablets to purchase: " << endl;
	    std::cin >> tablets;
	    cin.clear();

	cout << "Enter the number of computers to purchase: " << endl;
	    std::cin >> computers;

	//do the math ++++++++++++++++++++++++++++++++++++++
	    const double tabletcost = 320;
		const double computercost = 800;
		const double salestaxrate = 0.075;
		const double discountpercent = 0.10;
		const double financecharge = 0.15;
		std::cout << std::fixed << std::showpoint;
		std::cout << :setprecision(2);
		STD::cout << tabletcost << std::endl;
		

		//total cost of computers=cost per tablet * number of tablets purchased + cost per desktop * number of desktops purchased
		double devices;
		double totaltabletcost;
		double totalcomputercost;
		double totalordercost;

	        devices = tablets + computers; //total devices
		    totaltabletcost = tabletcost * tablets; //tablet costs
	        totalcomputercost = computercost * computers; //computer costs
	        totalordercost = totaltabletcost + totalcomputercost; //total order cost

	    double payingcash;
	    double cashdiscount;
	    double cashtax;
	    double cashbill;
	    double averagecashcost;

	        payingcash = totalordercost * discountpercent;
	        cashdiscount = totalordercost - payingcash; //total cost with cash
	        cashtax = cashdiscount * salestaxrate; //cash taxes
	        cashbill = cashdiscount + cashtax; //calculate total cash bill
	        averagecashcost = cashbill / devices; //average cash cost per device

	    double f financing;
	    double f financecost;
	    double f financetax;
	    double f financebill;
	    double f averagefinancecost;

	        financing = totalordercost * financecharge;
	        financecost = totalordercost + financing; //total cost with financing
	        financetax = financecost * salestaxrate; //financing taxes
	        financebill = financecost + financetax; //calculate total bill
	        averagefinancecost = financebill / devices; //average cash cost per device

	    double round savings;
	        savings = averagefinancecost - averagecashcost;

	//print invoice ++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	cout << "Invoice for " << companyname << ".\n\n";
	cout << "Cost for " << tablets << " Tablets is $" << totaltabletcost;
	cout << " at $" << tabletcost << " per Tablet.\n";
	cout << "Cost for " << computers << " Computers is $" << totalcomputercost << "\n\n";

	//invoce for cash
	cout << "If paying cash for the purchase\n";
	cout << "The subtotal is $" << cashdiscount << "\n";
	cout << "The tax is $" << cashtax << "\n";
	cout << "The total bill is $" << cashbill << "\n";
	cout << "The average cost per computer is $" << averagecashcost << "\n\n";

	//invoice for finance
	cout << "If financing the purchase\n";
	cout << "The subtotal is $" << financecost << "\n";
	cout << "The tax is $" << financetax << "\n";
	cout << "The total bill is $" << financebill << "\n";
	cout << "The average cost per computer is $" << averagefinancecost << "\n\n";

	//savings
	cout << "By paying cash you would save $" << savings << endl;
	

	system("Pause");
	    return 0;
};