#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
struct polling_PA{
	string CNIC;
	string constiuency;
	string affiliated_party;
	string name;
}candidate_PA[20];
void AddPAcandidate() {
	ofstream fout;
	fout.open("PA.txt", ios::app);
	ifstream fin;
	fin.open("PA.txt");
	char choice;
	int count = 0;
	for (int i = 0; i <= 20; i++) {
		cout << "Enter the Name of the Candidate" << endl;
		cin >> candidate_PA[i].name;
		while (fin >> candidate_PA[count].name) {
			if (candidate_PA[i].name == candidate_PA[count].name) {
				cout << "This data of this user already exist enter the name again" << endl;
				cin >> candidate_PA[i].name;
				break;
			}
			else { count + 4; }
		}
		cout << "Enter the CNIC of the Candidate" << endl;
		cin >> candidate_PA[i].CNIC;
		cout << "Enter the Party of the Candidate" << endl;
		cin >> candidate_PA[i].affiliated_party;
		cout << "Enter the Constituency of the Candidate" << endl;
		cin >> candidate_PA[i].constiuency;
		fout << candidate_PA[i].name << " " << candidate_PA[i].CNIC << " " << candidate_PA[i].affiliated_party << " " << candidate_PA[i].constiuency << endl;
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
void ViewPAcandidate() {
	ifstream fin;
	fin.open("PA.txt");
	if (!fin) {
		cout << "File is not available" << endl;
	}

	int count = 0;
	cout << left << setw(25) << "Name" << setw(15) << "CNIC" << setw(20) << "Affiliated_Party" << setw(10) << "Constituency" << endl;
	while (fin >> candidate_PA[count].name >> candidate_PA[count].CNIC >> candidate_PA[count].affiliated_party >> candidate_PA[count].constiuency) {
		cout << left << setw(25) << candidate_PA[count].name << setw(15) << candidate_PA[count].CNIC << setw(20) << candidate_PA[count].affiliated_party << setw(10) << candidate_PA[count].constiuency << endl;
		count++;
	}

	fin.close();
}
