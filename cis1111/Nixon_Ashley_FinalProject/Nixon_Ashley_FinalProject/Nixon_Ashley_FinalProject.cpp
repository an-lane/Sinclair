// Ashley Nixon
//CIS1111 Final Project
//Basketball Statistics
//program to record and analyze basketball quarter scores and determine the winner of a game, by how much did they win, and the average of a quarter.

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int teamAWin(int aFinal, int bFinal)
{
	int aWin = aFinal - bFinal;
	return aWin;
}

int teamBWin(int aFinal, int bFinal)
{
	int bWin = bFinal - aFinal;
	return bWin;
}

int averageA(int aAvg, int bAvg)
{
	int average = (aAvg + bAvg) / 2;
	return average;
}

int overtimeA(int otA, int otB)
{
	int otWinA = otA - otB;
	return otWinA;
}

int overtimeB(int otA, int otB)
{
	int otWinB = otB - otA;
	return otWinB;
}

int main()
{
	int score, scoreA[4], scoreB[4];
	int teamATotal, teamBTotal;
	int overTA = 0, overTB = 0;
	string teamA, teamB;
	const int team = 2, qtr = 4;
	string teams[team], nameTeam, ans;
	int scores[team][qtr];
	int i = 0, val, avg;

	//open files for data entry
	ofstream teamNames;
	teamNames.open("teamnames.txt");

	//team names
	cout << setw(52) << "\bBasketball Scores" << endl;
	cout << "Enter the short name of the first team: ";
	getline(cin, teamA);
	teamNames << teamA << "\n";
	cout << "\nEnter the short name of the second team: ";
	getline(cin, teamB);
	teamNames << teamB;
	teamNames.close();

	//quarter scores
	cout << "\n" << setw(10) << teamA << " Vs " << teamB << endl;

	ofstream teamRec;
	teamRec.open("teamrec.txt");


	//loop through quarters and write to file
	for (int j = 0; j < 4; j++)
	{
		cout << "\nEnter quarter " << +(j + 1) << " scores: ";
		
		cout << "\n" << teamA << " "; //recording for team A
		cin >> score;
		while (score < 0) //validate that score is not less than 0
		{
			cout << "Score may not be less than 0. ";
			cout << "\nRe-enter " << teamA << "'s score: ";
			cin >> score;
		}

		scoreA[j] = score;
		
		cout << teamB << " "; //recording for team B
		cin >> score;
		while (score < 0)
		{
			cout << "Score may not be less than 0. ";
			cout << "\nRe-enter " << teamB << "'s score: ";
			cin >> score;
		}
		scoreB[j] = score;
	}

	for (int j = 0; j < 4; j++) //record team A's score to file
	{
		teamRec << scoreA[j] << " ";
	}
	teamRec << "\n"; //break line to record to next line
	for (int j = 0; j < 4; j++) //record team B's score to file
	{
		teamRec << scoreB[j] << " ";
	}


	teamRec.close();

	//open teamnames.txt file and read team names
	ifstream readTeams;
	readTeams.open("teamnames.txt");
	if (readTeams.fail())
	{
		cout << "**teamnames.txt File Not Found**" << endl;
		return 1;
	}

	else
	{
		while (readTeams >> nameTeam)
		{
			teams[i] = nameTeam;
			i++;
			//this reads both team names and stores them to teams
		}
		readTeams.close();



		ifstream readQuarter;
		readQuarter.open("teamrec.txt");

		if (readQuarter.fail())
		{
			cout << "**teamrec.txt File Not Found**" << endl;
			return 1;
		}

		else
		{
			for (i = 0; i < team; i++)
			{
				for (int j = 0; j < qtr; j++)
				{
					readQuarter >> val;
					scores[i][j] = val;
				}
			}
			readQuarter.close();
		}




		//displays team scores
		cout << "\nTeams\t\t  1st\t   2nd\t     3rd\t4th" << endl;
		for (int i = 0; i < team; i++)
		{
			cout << setw(10) << left << teams[i];

			for (int j = 0; j < qtr; j++)
			{
				cout << setw(10) << right << scores[i][j];
			}
			cout << endl;
		}

		//math for team totals determining scores
		int teamATotal = 0, teamBTotal = 0;

		for (int j = 0; j < qtr; j++)
		{
			teamATotal += scores[0][j];
			teamBTotal += scores[1][j];
		}
		cout << "\nFinal score for " << teams[0] << " is " << teamATotal << " and " << teams[1] << " is " << teamBTotal << "\n";


		if (teamATotal > teamBTotal) 
		{
			
			int result = teamAWin(teamATotal, teamBTotal);
			cout << "\n\t\t " << teams[0] << " WON by " << result << " points!!!" << endl;
			
		}

		else if (teamATotal < teamBTotal) 
		{
			
			int result = teamBWin(teamATotal, teamBTotal);
			cout << "\n\t\t " << teams[1] << " WON by "<< result << " points!!! " << endl;
			
		}

		else if (teamATotal == teamBTotal)
		{
			do
			{
				cout << "\n\t Overtime: ";
				cout << "\t " << teams[0] << " VS " << teams[1] << endl;
				cout << "\nEnter " << teams[0] << " score: ";
				cin >> overTA;
				while (overTA < 0)
				{
					cout << "\nOvertime may not be less than 0. ";
					cin >> overTA;
				}

				cout << "Enter " << teams[1] << " score: ";
				cin >> overTB;
				while (overTB < 0)
				{
					cout << "\nOvertime may not be less than 0. ";
					cin >> overTB;
				}

			} while (overTA == overTB);

			if (overTA > overTB)
			{
				int result = overtimeA(overTA, overTB);
				cout << "\n\t\t" << teams[0] << " WON by " << result << " points!!!" << endl;
			}

			else if (overTA < overTB)
			{
				int result = overtimeB(overTA, overTB);
				cout << "\n\t\t" << teams[0] << " WON by " << result << " points!!!" << endl;
			}
		}

		//averages by quarter
		do
		{
			cout << "\nFor an average of points earned per quarter by quarter, select the quarter by number. (1-4)";
			cout << "\nFor an average of points by team, select 5 for " << teams[0] << "and 6 for " << teams[1] << ".";
			cout << "\nEnter any other number to quit.\n" << endl;
			cin >> avg;

			while (avg <= 0)
			{
				cout << "Selection error, please select a number greater than 0: ";
				cin >> avg;
			}

			if (avg >= 1 && avg <= 4)
			{
				//average by quarter selected.
				int result = averageA(scores[0][avg - 1], scores[1][avg - 1]);
				cout << "\nThe average score for quarter " << avg << " is " << result;
			}

			else if (avg == 5)
			{
				//average for team A
				cout << "\nThe average score for " << teams[0] << " is " << teamATotal / qtr << " for all four quarters.";	
				
			}

			else if (avg == 6)
			{
				//average for team B
				cout << "\nThe average score for " << teams[1] << " is " << teamBTotal / qtr << " for all four quarters.";
			}

			else
			{
				system("pause");			
			}
		} while (avg <= 6);
	}



	//system("pause");
	return 0;
}


