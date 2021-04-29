/*
  Ashley Nixon
  05-15-2019
  Baseball Statistics
  Program to generate some important statistics about the players. The information is called by Player number, at bats, hits, runs and rbi's.
*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const int SIZE = 10;

void calBatAvg(int playerNum[SIZE], int atBats[SIZE], int hits[SIZE], int batAvg[]) //calculate the batting average
{
	for (int i = 0; i < SIZE; i++)
	{
		batAvg[i] = round((float(hits[i]) / atBats[i]) * 1000);
	}
}

void loadArrays(int playerNum[SIZE], int atBats[SIZE], int hits[SIZE], int runs[SIZE], int rbis[SIZE], int batAvg[SIZE]) //read input data into the arrays with EOF loop.
{
	ifstream bstats;
	bstats.open("BaseballStats.txt"); //open for input operations. 

	int count = 0;

	while (!bstats.eof())
	{
		bstats >> playerNum[count];
		bstats >> atBats[count];
		bstats >> hits[count];
		bstats >> runs[count];
		bstats >> rbis[count];

		count++;
	}

	calBatAvg(playerNum, atBats, hits, batAvg); 

	bstats.close(); //closing the files
}

//print the neatly formatted tables with headings and one output line for each. Can put on one cout line, but for organization sake, putting each on it's own will help visualize.
void printStats(int playerNum[SIZE], int atBats[SIZE], int hits[SIZE], int runs[SIZE], int rbis[SIZE], int batAvg[SIZE], int N)
{
	cout << "Baseball Stats " << endl;
	cout << "\n\tPlayer Num   At Bats\tHits\tRuns\tRBIs\tBat Avg\t  Comment\n";
	
	for (int i= 0; i < N; i++)
	{
		cout << "\t    ";
		cout << playerNum[i] << " \t";
		cout << "\t" << atBats[i] << "\t";
		cout << " " << hits[i] << " \t";
		cout << " " << runs[i] << " \t";
		cout << " " << rbis[i] << " \t";
		cout << "  " << batAvg[i] << " \t";

		if (batAvg[i] >= 500 & batAvg[i] <= 1000) // defined by informaition given: 500-1000 is World Series scale.
			cout << " WORLD SERIES \n";
		else if (batAvg[i] >= 300 & batAvg[i] <= 499) //as above, but 300-499 is Farm League scale.
			cout << " FARM LEAGUE \n";
		else if (batAvg[i] >= 0 & batAvg[i] <= 299) //once again, 0-299 is Little League
			cout << " LITTLE LEAGUE \n";
	}
}

//function to calculate and output the total at bats, hits, runs, rbis, and team's batting average.
void teamBatAvg(int playerNum[SIZE], int atBats[SIZE], int hits[SIZE], int runs[SIZE], int rbis[SIZE], int batAvg[SIZE], int N)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += batAvg[i];
	}

	cout << "\nThe Team Batting Average is: " << round(float(sum /N)) << " \n";
}

//function to output the best and worst values, making sure to note which player achieved them.
void bestAndWorst(int playerNum[SIZE], int atBats[SIZE], int hits[SIZE], int runs[SIZE], int rbis[SIZE], int batAvg[SIZE], int N)
{
	int max = 0;
	int min = 0;

	for (int i = 0; i < N; i++)
	{
		if (batAvg[i] > batAvg[max])
			max = i;

		if (batAvg[i] < batAvg[min])
			min = i;
	}

	cout << "The Best Player is Player Number: " << playerNum[max] << " with a batting average of " << batAvg[max] << " \n";
	cout << "The Worst Player is Player Number: " << playerNum[min] << " with a batting average of " << batAvg[min] << " \n";
}

int main()
{
	int N = SIZE;

	int playerNum[SIZE], atBats[SIZE], hits[SIZE], runs[SIZE], rbis[SIZE], batAvg[SIZE];

	loadArrays(playerNum, atBats, hits, runs, rbis, batAvg);

	printStats(playerNum, atBats, hits, runs, rbis, batAvg, N);

	cout << " ";

	teamBatAvg(playerNum, atBats, hits, runs, rbis, batAvg, N); //call and print the teams batting average
	bestAndWorst(playerNum, atBats, hits, runs, rbis, batAvg, N);

	return 0;
}