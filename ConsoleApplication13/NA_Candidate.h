#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
struct polling_NA{
	string CNIC;
	string constiuency;
	string affiliated_party;
	string name;
}candidate_NA[20];
void AddNAcandidate() {
	ofstream fout;
	fout.open("NA.txt", ios::app);
	ifstream fin;
	fin.open("NA.txt");
	int count = 0;
	char choice;
	for (int i = 0; i <= 20; i++) {
		cout << "Enter the Name of the Candidate" << endl;
		cin >> candidate_PA[i].name;
		while (fin >> candidate_PA[count].name) {
			if (candidate_NA[i].name == candidate_NA[count].name) {
				cout << "This data of this user already exist enter the name again" << endl;
				cin >> candidate_NA[i].name;
				break;
			}
			else { count + 4; }
		}
		cout << "Enter the CNIC of the Candidate" << endl;
		cin >> candidate_NA[i].CNIC;
		cout << "Enter the Party of the Candidate" << endl;
		cin >> candidate_NA[i].affiliated_party;
		cout << "Enter the Constituency of the Candidate" << endl;
		cin >> candidate_NA[i].constiuency;
		fout << candidate_NA[i].name << " " << candidate_NA[i].CNIC << " " << candidate_NA[i].affiliated_party << " " << candidate_NA[i].constiuency << endl;
		cout << "Enter 'Y' if you want to add the data of another candidate and press any other button to exit" << endl;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			continue;
		}
		else {
			break;
		}
	}
	fout.close();
}
void ViewNAcandidate() {
	ifstream fin;
	fin.open("NA.txt");
	if (!fin) {
		cout << "File is not available" << endl;
	}

	int count = 0;
	cout << left << setw(25) << "Name" << setw(15) << "CNIC" << setw(20) << "Affiliated_Party" << setw(10) << "Constituency" << endl;
	while (fin >> candidate_NA[count].name >> candidate_NA[count].CNIC >> candidate_NA[count].affiliated_party >> candidate_NA[count].constiuency) {
		cout << left << setw(25) << candidate_NA[count].name << setw(15) << candidate_NA[count].CNIC << setw(20) << candidate_NA[count].affiliated_party << setw(10) << candidate_NA[count].constiuency << endl;
		count++;
	}

	fin.close();
}