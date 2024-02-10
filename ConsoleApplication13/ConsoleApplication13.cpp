#include<iostream>
#include<fstream>
#include<iomanip>
#include "PA_Candidate.h"
#include"NA_Candidate.h"
#include"Voter_Info.h"
using namespace std;
void menu();
void ViewNAcandidate();
void AddNAcandidate();
void AddPAcandidate();
void ViewPAcandidate();
void AddVoterInfo();
void ViewVoterInfo();
void SearchVoterInfo();
int main() {
	while (true) {
		menu();
	};
	return 0;
}
void menu() {
	cout << "*******Voting Management System*******" << endl;
	cout << endl;
	cout << "**************************************" << endl;
	int menuchoice;
	int choice;
	cout << "**Select The Option**" << endl;
	cout << "1:Manage NA Candidate\n2:Manage PA Candidate\n3:Check Information of Voter\n0:Exit" << endl;
	cin >> menuchoice;
	switch (menuchoice) {
	case 1:
		cout << "**Select the function**" << endl;
		cout << "1:Add_NA_Candidate\n2:View_NA_Candidate\n0:Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:

			AddNAcandidate();
			break;
		case 2:
			ViewNAcandidate();
			break;
		case 0:
			exit(0);
		
		}
		break;
	case 2:
		cout << "**Select the function**" << endl;
		cout << "1:Add_PA_Candidate\n2:View_PA_Candidate\n0:Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			AddPAcandidate();
			break;
		case 2:
			ViewPAcandidate();
			break;
		case 0:
			exit(0);
		}
		break;
	case 3:
		cout << "**Select the function**" << endl;
		cout << "1:Add_Voter_Info\n2:View_Voter_Info\n3:Search_Voter_Info\n0:Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			AddVoterInfo();
			break;
		case 2:

			ViewVoterInfo();
			break;
		case 3:
			SearchVoterInfo();
			break;
		case 0:
			exit(0);
		}
		break;
	case 0:
		exit(0);
	}
}
