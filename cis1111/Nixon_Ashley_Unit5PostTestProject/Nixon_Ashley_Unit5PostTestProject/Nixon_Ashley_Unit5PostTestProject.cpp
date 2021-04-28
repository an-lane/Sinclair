// Ashley Nixon
//CIS 1111
//02/27/2019
//Unit 5 PreTest Project - Financial Formulas
// A C++ program to calculate 5 financial formulas*. The customer will enter 10 fiancial numbers and then select one of the formulas. Display the answer to each formula selected.


#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

    //first! List the functions per formula. They are listed in the Project information or http://www.bankrate.com/finance/investing/financial-formulas-2.aspx
    //Cash Flow
	double cashFlow(double income, double expense)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "\nYour cash flow is " << income - expense << "\n";
		return 0;
	}

	//Leverage Ratio
	double leverageRatio(double totalDebit, double totalEquity)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "\nYour leverage ratio is " << totalDebit / totalEquity << "\n";
		return 0;
	}

	//Real Return
	double realReturn(double investmentReturn, double inflationRate)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "\nYour real return is " << ((1 + investmentReturn) / (1 + inflationRate) - 1) * 100 << "\n";
		return 0;
	}

	//Percentage Increase
	double percentageIncrease(double marketPrice, double purchasePrice)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "\nYour percentage increase is " << (marketPrice - purchasePrice) / purchasePrice << "\n";
		return 0;
	}

	//Years to Double Investment
	double doubleInvestment(double annlInvestmentRate)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "\nYour years to double investment " << 72 / (annlInvestmentRate) / 100 << "\n";
		return 0;
	}

	//menu with all options. allow for each option to be continually chosen. case is a great option for this. 
	int menu(double income, double expense, double totalDebit, double totalEquity, double investmentReturn, double inflationRate, double marketPrice, double purchasePrice, double annlInvestmentRate)
	{
		int selection = 0;
		cout << "\nEnter which formula to solve: ";
		cout << "\n1     Cash Flow\n2     Leverage Ratio\n3     Real Return\n4     Percentage Increase\n5     Years to Double Investment\nChoose Any Other Number to Exit.\n";
		cin >> selection;
		
		if ((selection >= 1) || (selection <= 5))
		{
			switch (selection)
			{
			 case 1:
				cashFlow(income, expense);
				menu(income, expense, totalDebit, totalEquity, investmentReturn, inflationRate, marketPrice, purchasePrice, annlInvestmentRate);
				break;
			 case 2:
				leverageRatio(totalDebit, totalEquity);
				menu(income, expense, totalDebit, totalEquity, investmentReturn, inflationRate, marketPrice, purchasePrice, annlInvestmentRate);
				break;
			 case 3:
				realReturn(investmentReturn, inflationRate);
				menu(income, expense, totalDebit, totalEquity, investmentReturn, inflationRate, marketPrice, purchasePrice, annlInvestmentRate);
				break;
			 case 4:
				percentageIncrease(marketPrice, purchasePrice);
				menu(income, expense, totalDebit, totalEquity, investmentReturn, inflationRate, marketPrice, purchasePrice, annlInvestmentRate);
				break;
			 case 5:
				doubleInvestment(annlInvestmentRate);
				menu(income, expense, totalDebit, totalEquity, investmentReturn, inflationRate, marketPrice, purchasePrice, annlInvestmentRate);
				break;
			 default:
				break;
			}
		   }
		return 0;
	}

	//here's the main body of the code, what will be displayed. 
	int main()
	{
		double income, expense, totalDebit, totalEquity, investmentReturn, inflationRate, marketPrice, purchasePrice, annlInvestmentRate;

		cout << "\nPlease enter the following information:\n";
		//income
		cout << "\nIncome: ";
		cin >> income;
		//expenses
		cout << "Expenses: ";
		cin >> expense;
		//total debit
		cout << "Total Debit: ";
		cin >> totalDebit;
		//total equity = this may not be 0
		cout << "Total Equity: ";
		cin >> totalEquity;
		    if (totalEquity == 0)
		    {
				cout << "You cannot enter 0 for total equity.";
				cout << "Total Equity: ";
				cin >> totalEquity;
			}
		//return on investments
		cout << "Return on Investment: ";
		cin >> investmentReturn;
		//inflation rates
		cout << "Inflation Rate: ";
		cin >> inflationRate;
		//market price
		cout << "Market Price of Asset: ";
		cin >> marketPrice;
		//purchase price = this may not be 0
		cout << "Purchase Price of Asset: ";
		cin >> purchasePrice;
			if (purchasePrice == 0)
			{
				cout << "You cannot enter 0 for purchase price.";
				cout << "Purchase Price of Asset: ";
				cin >> purchasePrice;
			}
		//annual interest rate of investments = this may not be 0
		cout << "Annual Interest Rate of Investment: ";
		cin >> annlInvestmentRate;
			if (annlInvestmentRate == 0)
			{
				cout << "You cannot enter 0 for annual interest rate.";
				cout << "Annual Interest Rate of Investment: ";
				cin >> annlInvestmentRate;
			}
			//allow to return to menu.
			menu(income, expense, totalDebit, totalEquity, investmentReturn, inflationRate, marketPrice, purchasePrice, annlInvestmentRate);
			return 0;
	}