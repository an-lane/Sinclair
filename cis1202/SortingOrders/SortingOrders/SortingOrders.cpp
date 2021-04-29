// SortingOrders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

#define arraySize 8

void Display(int[]);
void BubbleSort(int[]);
void SelectionSort(int[]);

int main()
{
	int arra1[] = { 7,35,22,48,27,65,2,8 };
	int arra2[] = { 7,35,22,48,27,65,2,8 };

	cout << "First array: \n";
	Display(arra1);
	cout << endl;

	cout << "Bubble sort: " << endl;
	BubbleSort(arra1);

	cout << "\nSecond array: \n";
	Display(arra2);
	cout << endl;

	cout << "Selection sort: " << endl;
	SelectionSort(arra2);
	cout << endl;

	return 0;
}

void Display(int arra[]) {
	for (int i = 0; i < arraySize; i++)
		cout << arra[i] << " ";
	cout << endl;
}

void BubbleSort(int arra[]) {
	for (int i = arraySize - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (arra[j] > arra[j + 1])
			{
				int tmp = arra[j];
				arra[j] = arra[j + 1];
				arra[j + 1] = tmp;
				Display(arra);
			}
		}
	}
}

void SelectionSort(int arra[]) {
	for (int i = 0; i < arraySize - 1; i++)
	{
		for(int j=i+1;j<arraySize;j++)
			if(arra[i]>arra[j])
				{
					int tmp = arra[i];
					arra[i] = arra[j];
					arra[j]=tmp;
					Display(arra);
				}
	}
}