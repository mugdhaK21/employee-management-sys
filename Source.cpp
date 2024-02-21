#ifndef Employee_Management_CPP
#define Employee_Management_CPP
#include<iostream>
#include<cstring>
#include "Header.h"
#include<iostream>
#include<fstream>
using namespace std;

void Employee_management::menu()
{
	//menu for thr main program 
	while (true)
	{
		int choice;
		char x; // Options to choose an action
		//system("cls");
		cout << "\n\t\t\t\t\t-------------------------------" << endl;
		cout << "\t\t\t\t\t>> EMPLOYE MANAGEMENT SYSTEM <<" << endl;
		cout << "\t\t\t\t\t-------------------------------" << endl;
		cout << "\t\t\t\t\t 1. Enter New Record" << endl;
		cout << "\t\t\t\t\t 2. Display Record" << endl;
		cout << "\t\t\t\t\t 3. Modify Record" << endl;
		cout << "\t\t\t\t\t 4. Search Record" << endl;
		cout << "\t\t\t\t\t 5. Delete Record" << endl;
		cout << "\t\t\t\t\t 6. Exit" << endl;

		cout << "\t\t\t\t\t.................................." << endl;
		cout << "\t\t\t\t\t>> Choice Options: [1/2/3/4/5/6] <<" << endl;
		cout << "\t\t\t\t\t.................................." << endl;
		cout << " Enter Your Choice: "; // Taking the action input
		cin >> choice;
		// Calling relevant function as per choice
		switch (choice)
		{
		case 1:
			do
			{
				insert();
				cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
				cin >> x;
			} while (x == 'y' || x == 'Y');
			//waitForEnter();
			break;
		case 2:
			display();
			break;
		case 3:
			modify();
			break;
		case 4:
			search();
			break;
		case 5:
			deleted();
			break;
		case 6:
			system("cls");
			cout << "\n\t\t\t>> EMPLOYE MANAGEMENT SYSTEM  <<\n\n";

			exit(0);
		default:
			cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
		}
	}
}



void Employee_management::insert()
{
	//system("cls");
	fstream file;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Employee Insert Data -------------------------------------------" << endl;
	cout << "\n Enter Name of Employee: ";
	cin >> name;
	cout << "\n Enter Employee ID [max 4 digits]: ";
	cin >> id;
	cout << "\n Enter Designation: ";
	cin >> designation;
	cout << "\n Enter Employee Age: ";
	cin >> age;
	cout << "\n Enter Employee CTC: ";
	cin >> ctc;
	cout << "\n Enter Employee Experience: ";
	cin >> experience;
	cout << "\n ENTER PERKS: ";
	cin >> perks;
	cout<< "\n Enter Employee ALLOWNANCE: ";
	cin>>allowances;
	cout << "\n Enter Employee INCENTIVES: ";
	cin>>incentives;
	file.open("Employee_Record.txt", ios::app | ios::out);
	file << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience <<" "<< perks <<" " << allowances<<" " << incentives << "\n";
	file.close();

}
void Employee_management::display()
{
	
	int total = 1;
	fstream file;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Employee Record Data -------------------------------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
	if (!file)
	{
		cout << "\n\t\t\tNo Data is Present... ";
		file.close();
	}
	else
	{
		file >> name >> id >> designation >> age >> ctc >> experience;
		cout << "\n -------------------------------------------------------------------------------------------------------------------------------------------------------";
		cout << "\n||    NAME    ||    ID    ||    DESIGNATION    ||    AGE    ||      CTC      ||    EXPERIENCE    ||    PERKS    ||    ALLOWNANCE   ||   INCENTIVES  ||";
		cout << "\n -------------------------------------------------------------------------------------------------------------------------------------------------------";
		while (!file.eof())
		{
			cout << "\n";
			cout << total++ << ". " << name << "\t  " << id << "\t\t  " << designation << "\t\t   " << age << "\t\t  " << ctc << "\t\t" << experience << "\t\t" << perks << "\t\t" << allowances << "\t\t"<< incentives ;
			file >> name >> id >> designation >> age >> ctc >> experience>> perks>> allowances>> incentives;
		}
	}
	file.close();
	waitForEnter();

}
void Employee_management::modify()
{
	system("cls");
	char checkId[5];
	int found = 0;
	fstream file, file1;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Employee Modify Data ------------------------------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
	if (!file)
	{
		cout << "\n\t\t\tNo Data is Present..";
		file.close();
	}
	else
	{
		cout << "\nEnter employee id: ";
		cin >> checkId;
		file1.open("record.txt", ios::app | ios::out);
		file >> name >> id >> designation >> age >> ctc >> experience >> perks >> allowances >> incentives;
		while (!file.eof())
		{
			if (strcmp(checkId, id) == 0)
			{
				cout << "\n Enter Name of Employee: ";
				cin >> name;
				cout << "\n Enter Employee ID [max 4 digits]: ";
				cin >> id;
				cout << "\n Enter Designation: ";
				cin >> designation;
				cout << "\n Enter Employee Age: ";
				cin >> age;
				cout << "\n Enter Employee CTC: ";
				cin >> ctc;
				cout << "\n Enter Employee Experience: ";
				cin >> experience;
				cout << "\n ENTER PERKS: ";
				cin >> perks;
				cout << "\n Enter Employee ALLOWNANCE: ";
				cin >> allowances;
				cout << "\n Enter Employee INCENTIVES: ";
				cin >> incentives;
				cout << "\n\nSuccessfully Modify Details Of Employee";
				file << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << " " << perks << " " << allowances << " " << incentives << "\n";
				found++;
			}
			else
			{
				file << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << " " << perks << " " << allowances << " " << incentives << "\n";
			}
			file >> name >> id >> designation >> age >> ctc >> experience >> perks >> allowances >> incentives;
		}
		if (found == 0)
		{
			cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
		}
		file1.close();
		file.close();
		remove("Employee_Record.txt");
		rename("record.txt", "Employee_Record.txt");
	}
	waitForEnter();
}
void Employee_management::search()
{
	system("cls");
	fstream file;
	char checkId[5];
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
	cout << "\n\nEnter Employee ID: ";
	cin >> checkId;
	if (!file)
	{
		cout << "\n\t\t\tNo Data is Present... ";
		file.close();
	}
	else
	{
		file >> name >> id >> designation >> age >> ctc >> experience >> perks >> allowances >> incentives;
		while (!file.eof())
		{
			if (strcmp(checkId, id) == 0)
			{
				cout << "\n---------------------\n";
				cout << "Employee Name: " << name << "\n";
				cout << "Employee ID.: " << id << "\n";
				cout << "Employee Designation: " << designation << "\n";
				cout << "Employee Age: " << age << "\n";
				cout << "Employee CTC: " << ctc << "\n";
				cout << "Employee Experience: " << experience << "\n";
				cout << "Employee Perks: " << perks << "\n";
				cout << " Employeee Allowances: " << allowances << "\n";
				cout << "Employee Incentives: " << incentives << "\n";
				cout << "---------------------\n";
			}
			file >> name >> id >> designation >> age >> ctc >> experience >> perks >> allowances >> incentives;
		}
	}
	file.close();
	waitForEnter();
}
void Employee_management::deleted()
{
	system("cls");
	char checkId[5];
	fstream file, file1;
	int found = 0;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
	if (!file)
	{
		cout << "\n\t\t\tNo Data is Present..";
		file.close();
	}
	else
	{
		cout << "\nEnter Employee Id To Remove Data: ";
		cin >> checkId;
		file1.open("record.txt", ios::app | ios::out);
		file >> name >> id >> designation >> age >> ctc >> experience >> perks >> allowances >> incentives;
		while (!file.eof())
		{
			if (strcmp(checkId, id) != 0)
			{
				file << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << " " << perks << " " << allowances << " " << incentives << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tSuccessfully Delete Data";
			}
			file >> name >> id >> designation >> age >> ctc >> experience >> perks >> allowances >> incentives;
		}
		if (found == 0)
		{
			cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
		}
		file1.close();
		file.close();
		remove("Employee_Record.txt");
		rename("record.txt", "Employee_Record.txt");
		waitForEnter();
	}
}

void Employee_management::waitForEnter()
{
	cout << "\n\nPress enter to go back: ";
	cin.get();
}



#endif
