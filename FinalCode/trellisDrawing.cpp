#include "trellisDrawing.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>
#include<string>
using namespace std;




trellisDrawing::trellisDrawing()
{
}

trellisDrawing::trellisDrawing(vector<int>vec) {


	vec2 = vec;


}


trellisDrawing::~trellisDrawing()
{
}

void trellisDrawing::trellisTable()
{

	char firstDigOfState[8];
	char secondDigOfState[8];
	char lastDigOfState[8];

	char shift3 = 0;
	char shift2 = 0;
	char shift1 = 0;

	firstDigOfState[0] = '0'; secondDigOfState[0] = '0'; lastDigOfState[0] = '0';
	firstDigOfState[1] = '0'; secondDigOfState[1] = '0'; lastDigOfState[1] = '1';
	firstDigOfState[2] = '0'; secondDigOfState[2] = '1'; lastDigOfState[2] = '0';
	firstDigOfState[3] = '0'; secondDigOfState[3] = '1'; lastDigOfState[3] = '1';
	firstDigOfState[4] = '1'; secondDigOfState[4] = '0'; lastDigOfState[4] = '0';
	firstDigOfState[5] = '1'; secondDigOfState[5] = '0'; lastDigOfState[5] = '1';
	firstDigOfState[6] = '1'; secondDigOfState[6] = '1'; lastDigOfState[6] = '0';
	firstDigOfState[7] = '1'; secondDigOfState[7] = '1'; lastDigOfState[7] = '1';

	for (int row = 0; row < 8; row++)
	{ // 8 is the maximum number of states

		cout << firstDigOfState[row] << secondDigOfState[row] << lastDigOfState[row] << "(" << row << "): ";

		if (firstDigOfState[row] == '0' && secondDigOfState[row] == '0' && lastDigOfState[row] == '0') {

			cout << "  x    :";


		}
		else {

			cout << "       :";
		}

		firstDigOfState[row] = firstDigOfState[row] - 48;
		secondDigOfState[row] = secondDigOfState[row] - 48;
		lastDigOfState[row] = lastDigOfState[row] - 48;

		for (int column = 0; column < vec2.size(); column++) {

			shift3 = shift2;
			shift2 = shift1;
			shift1 = vec2[column];

			if (shift1 == firstDigOfState[row] && shift2 == secondDigOfState[row] && shift3 == lastDigOfState[row]) {

				cout << "   x   :";
			}
			else {
				cout << "       :";
			}



		}

		firstDigOfState[row] = firstDigOfState[row] + 48;
		secondDigOfState[row] = secondDigOfState[row] + 48;
		lastDigOfState[row] = lastDigOfState[row] + 48;
		cout << endl;
	}



}



void trellisDrawing::saveToFile() {

	ofstream savingToAFile("saveOutputToAFile.txt");

	char firstDigOfState[8];
	char secondDigOfState[8];
	char lastDigOfState[8];

	char shift3 = 0;
	char shift2 = 0;
	char shift1 = 0;

	firstDigOfState[0] = '0'; secondDigOfState[0] = '0'; lastDigOfState[0] = '0';
	firstDigOfState[1] = '0'; secondDigOfState[1] = '0'; lastDigOfState[1] = '1';
	firstDigOfState[2] = '0'; secondDigOfState[2] = '1'; lastDigOfState[2] = '0';
	firstDigOfState[3] = '0'; secondDigOfState[3] = '1'; lastDigOfState[3] = '1';
	firstDigOfState[4] = '1'; secondDigOfState[4] = '0'; lastDigOfState[4] = '0';
	firstDigOfState[5] = '1'; secondDigOfState[5] = '0'; lastDigOfState[5] = '1';
	firstDigOfState[6] = '1'; secondDigOfState[6] = '1'; lastDigOfState[6] = '0';
	firstDigOfState[7] = '1'; secondDigOfState[7] = '1'; lastDigOfState[7] = '1';

	for (int row = 0; row <= 7; row++)
	{ // 8 is the maximum number of states

		savingToAFile << firstDigOfState[row] << secondDigOfState[row] << lastDigOfState[row] << "(" << row << "): ";

		if (firstDigOfState[row] == '0' && secondDigOfState[row] == '0' && lastDigOfState[row] == '0') {

			savingToAFile << "  x    :";


		}
		else {

			savingToAFile << "       :";
		}

		for (int column = 0; column < vec2.size(); column++) {

			shift3 = shift2;
			shift2 = shift1;
			shift1 = vec2[column];


			firstDigOfState[row] = firstDigOfState[row] - 48;
			secondDigOfState[row] = secondDigOfState[row] - 48;
			lastDigOfState[row] = lastDigOfState[row] - 48;


			if (shift1 == firstDigOfState[row] && shift2 == secondDigOfState[row] && shift3 == lastDigOfState[row]) {

				savingToAFile << "   x   :";
			}
			else {
				savingToAFile << "       :";
			}

			firstDigOfState[row] = firstDigOfState[row] + 48;
			secondDigOfState[row] = secondDigOfState[row] + 48;
			lastDigOfState[row] = lastDigOfState[row] + 48;

		}

		savingToAFile << endl;
	}


}