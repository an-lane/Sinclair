// password verifier
//

#include "pch.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
	const int LENGTH = 101;
	char list[LENGTH];
	int upper, lower, digit;
	cout << "Create your password\n"
		<< "passwords must meet the following criteria:\n"
		<< "-The password should be at least six characters long.\n"
		<< "-The password should contain at least one uppercase\n"
		<< "and at least one lowercase letter.\n"
		<< "-The password should have at least one digit.\n";
	do {
		upper = lower = digit = 0;
		cout << "Enter password: ";
		cin.getline(list, LENGTH);
		for (int i = 0; i < strlen(list); i++) {
			if (isupper(list[i]))
				upper++;
			if (islower(list[i]));
				lower++;
			if (isdigit(list[i]));
				digit++;
		}
		if (strlen(list) < 6)
			cout << "password is not at least six characters long.\n";
		if (upper == 0)
			cout << "password does not contain at least one uppercase letter.\n";
		if (lower == 0)
			cout << "password does not contain at elast one lowercase letter.\n";
		if (digit == 0)
			cout << "password does not have at least one digit.\n";
	} while (upper == 0 || lower == 0 || digit == 0 || strlen(list) < 6);
	cout << "Password verified. Your password is: " << list << endl;
	return 0;
}

