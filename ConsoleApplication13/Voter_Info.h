#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
struct voter {
	string name;
	int House_No;
	string CNIC;
	string PA_Constituency;
	string NA_Constituency;
	int Serial_num;
}info[20];
void AddVoterInfo() {
	ofstream fout;
	fout.open("Voter.txt", ios::app);
	ifstream fin;
	fin.open("Voter.txt");
	char choice;
	int count = 0;
	for (int i = 0; i <= 20; i++) {
		cout << "Enter the CNIC of the Voter" << endl;
		cin >> info[i].CNIC;
		while (fin >> info[count].CNIC) {
			if (info[i].name == info[count].name) {
				cout << "This data of this user already exist enter the CNIC again" << endl;
				cin >> info[i].CNIC;
				break;
			}
			else { count + 6; }
		}
		cout << "Enter the Name of the Voter" << endl;
		cin >> info[i].name;
		cout << "Enter the House Number of the Voter" << endl;
		cin >> info[i].House_No;
		cout << "Enter the Serial Number of the Voter" << endl;
		cin >> info[i].Serial_num;
		cout << "Enter the PA_Constituency of the Voter" << endl;
		cin >> info[i].PA_Constituency;
		cout << "Enter the NA_Constituency of the Voter" << endl;
		cin >> info[i].NA_Constituency;
		fout << info[i].CNIC << " " << info[i].name << " " << info[i].House_No << " " << info[i].Serial_num << " " << info[i].PA_Constituency << " " << info[i].NA_Constituency << endl;
		cout << "Enter 'Y' if you want to add the data of another Voter and press any other button to exit" << endl;
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
void ViewVoterInfo() {
	ifstream fin;
	fin.open("Voter.txt");
	if (!fin) {
		cout << "File is not available" << endl;
	}

	int count = 0;
	cout << left << setw(15) << "CNIC" << setw(15) << "Name" << setw(15) << "House_Number" << setw(15) << "Serial_Number" << setw(20) << "PA_Constituency" << setw(20) << "NA_Constituency" << endl;
	while (fin >> info[count].CNIC >> info[count].name >> info[count].House_No >> info[count].Serial_num >> info[count].PA_Constituency >> info[count].NA_Constituency) {
		cout << left << setw(15) << info[count].CNIC << setw(15) << info[count].name << setw(15) << info[count].House_No << setw(15) << info[count].Serial_num << setw(20) << info[count].PA_Constituency << setw(20) << info[count].NA_Constituency << endl;
		count++;
	}

	fin.close();
}
void SearchVoterInfo() {
	ifstream fin;
	fin.open("Voter.txt");
	if (!fin) {
		cout << "File is not Available" << endl;
	}
	string Search_CNIC;
	cout << "Enter the CNIC of the person you want to find the info for" << endl;
	cin >> Search_CNIC;
	int count = 0;
	while (fin >> info[count].CNIC >> info[count].name >> info[count].House_No >> info[count].Serial_num >> info[count].PA_Constituency >> info[count].NA_Constituency) {
		if (Search_CNIC == info[count].CNIC) {
			cout << "Your Voting Info in the Data is Present" << endl;
			cout << left << setw(15) << "CNIC" << setw(15) << "Name" << setw(15) << "House_Number" << setw(15) << "Serial_Number" << setw(20) << "PA_Constituency" << setw(20) << "NA_Constituency" << endl;
			cout << left << setw(15) << info[count].CNIC << setw(15) << info[count].name << setw(15) << info[count].House_No << setw(15) << info[count].Serial_num << setw(20) << info[count].PA_Constituency << setw(20) << info[count].NA_Constituency << endl;
			break;
		}
		else { count + 6; }
	}

}
