#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cmath>
#include"trellisDrawing.h"
using namespace std;

bool isNumber(string s) {

	for (int i = 0; i < s.length(); i++) {

		if (isdigit(s[i]) == false)
			return false;
	}

	return true;
}
int main() {
start:
	cout << "Resit Convolutional Encoder Program with SID " << endl;
	cout << "Nabil Safwat, ID - 8055129" << endl;
	cout << "My Generator Polynomials are 8, 0 and 5" << endl;
	cout << "The Registers Outputs are A = G(010), B = G(001), C = G(101)" << endl;
	cout << endl;


	int reg1 = 0, reg2 = 0, reg3 = 0;
	int outputA, outputB, outputC;

	vector<int> V;

	string inputFromUser;
	cout << "Enter 'T' if you wish to read inputs from a file or input your digits directly from keyboard :" << endl;
	getline(cin, inputFromUser);

	if (isNumber(inputFromUser)) { // Keyboard input into the vector

		int i = 0;
		for (int i = 0; i < inputFromUser.size(); i++)
			V.push_back(inputFromUser[i] - 48);

		cout << "Inputs read successfully.." << endl;
		cout << endl;
	}



	else if (inputFromUser == "T") { // Reading from textfile into the vector

		ifstream readingFromTxt;
		string nameOfFile;
		cout << "Enter the name of your text file to read from : " << endl;
		cin >> nameOfFile;
		readingFromTxt.open(nameOfFile);

		if (readingFromTxt) {

			double value;

			while (readingFromTxt >> value) {

				V.push_back(value);
			}


		}

		cout << "File inputs read successfully..." << endl;
		cout << endl;


	}

	else {

		cout << "Invalid input, sir!" << endl;

	}

	if (all_of(V.begin(), V.end(), [](int value) {
		return value == 0 || value == 1;
	})) {
	}

	else {

		cout << "Your entered values are not all binary!" << endl;
		cout << endl;
		goto start;
	}

	cout << "Trellis diagram showing the state changes:" << endl;
	cout << "Input : n/a,         ";
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << ",      ";
	cout << "..." << endl;

	//Encoder

	cout << "Output: n/a,       ";



	for (int i = 0; i < V.size(); i++) {

		reg3 = reg2;
		reg2 = reg1;
		reg1 = V[i];

		outputA = reg2;
		outputB = reg3;
		outputC = (reg1 ^ reg3);

		cout << outputA << outputB << outputC << ",    ";

	}
	cout << "  ...";
	cout << endl;
	cout << "Current State" << setfill('-') << setw(10) << '-';
	for (int i = 0; i < V.size(); i++) {

		cout << setfill('-') << setw(8) << '-';
	}

	cout << '-' << endl;


	//Trellis from class
	trellisDrawing trellisdrawing;

	trellisdrawing.vec2 = V; // Copying to vec2 of class file from V

	trellisdrawing.trellisTable();


	// save
	cout << endl;
	string saveToFile;
	cout << "Do you want to save the output to a text file, user?" << endl;
	cin >> saveToFile;

	if (saveToFile == "Y") {

		cout << "Saved successfully..." << endl;
		trellisdrawing.saveToFile();


	}


	else if (saveToFile == "N") {

		cout << "Okay, proceeding with the program..." << endl;


	}


	//rerun

	string rerunTheProgram;
	cout << "Do you want to re-run the whole program?" << endl;
	cin >> rerunTheProgram;
	cin.ignore();


	if (rerunTheProgram == "Y") {

		cout << "The whole system will be available for you again." << endl;
		cout << endl;
		system("CLS");
		goto start;



	}

	else if (rerunTheProgram == "N") {

		cout << "Thank you, Goodbye!" << endl;

		return 0;
	}



}