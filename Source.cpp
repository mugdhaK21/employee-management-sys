#ifndef Source_CPP
#define Source_CPP
#include<iostream>
#include<cstring>
#include "Header.h"
#include<iostream>
#include <utility> // for std::pair
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

Attendance::Attendance() {

}


void Attendance::setDaysPresent() {
    int d;
    cout << "Enter the days the employee was present: ";
    cin >> d;
    daysPresent = d;
}

int Attendance::getDaysPresent() const {
    return daysPresent;
}
void Attendance::setAttendance() {
    cout << "TOTAL WORKING DAYS: ";
    cin >> total_workingdays;

    attendance = (float)daysPresent / total_workingdays * 100;

}

int Attendance::getAttendance() {
    return attendance;
}


void Employee::display() const
{
    cout << endl;
    cout << endl;
    cout << "Name : " << name << endl;
    cout << "Employee ID: " << employeeId << endl;
    cout << "Base Salary: $" << baseSalary << endl;
 
}

void Employee::setAtt() {
    eAttendance = new Attendance();
    eAttendance->setDaysPresent();
    eAttendance->setAttendance();
}

int Employee::getEAtt() {
    return eAttendance->getAttendance();
}

int Employee::getEmployeeId()
{
    return employeeId;
}

void Employee::setBaseSalary(double salary) {
    baseSalary = salary;
}

//-------------------------------------------------------------------------------------------------------------//

double RegularEmployee::calculateSalary() const {
    return baseSalary + perks + allowances;
}


void RegularEmployee::display() const {
    Employee::display();
    cout << "Perks: $" << perks << ", Allowances: $" << allowances << endl;
}

//--------------------------------------------------------------------------------------------------------------//

double ContractEmployee::calculateSalary() const {
    return baseSalary + incentives;
}

void ContractEmployee::display() const {
    Employee::display();
    cout << "Incentives: $" << incentives << endl;
}
//-------------------------------------------------------------------------------------------------------------------// 



void PayrollSystem::addEmployee(Employee* emp)
{
    employees.push_back(emp);
}


void PayrollSystem::displayAllEmployees() const
{
    vector<Employee*> sortedEmployees = employees;
    sort(sortedEmployees.begin(), sortedEmployees.end(), [](Employee* a, Employee* b) {
        return a->calculateSalary() > b->calculateSalary();
        });

    for (Employee* emp : sortedEmployees) {
        emp->display();
        cout << "Attendance: ";
        cout << emp->getEAtt();
        cout << endl;
        cout << endl;
   
    }
}

pair<Employee*, int> PayrollSystem::searchEmployeeById(int id) const {
    for (Employee* emp : employees) {
       /* If a match is found, this line creates a pair using the make_pair function. 
        The first element of the pair is a pointer to the employee object (emp), 
            and the second element is the employee's attendance, obtained using the getEAtt method.*/
        if (emp->getEmployeeId() == id) {

            //make pair function to get emloyee details with attendance 
            return make_pair(emp, emp->getEAtt());
        }
    }
    return make_pair(nullptr, -1); // Return nullptr and -1 if employee not found
}


void PayrollSystem::deleteEmployee(int id) {
    auto it = remove_if(employees.begin(), employees.end(), [id](Employee* emp) {
        return emp->getEmployeeId() == id;
        });

    if (it != employees.end()) {
        delete* it;
        employees.erase(it);
        cout << "Employee with ID " << id << " deleted successfully." << endl;
    }
    else {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}



void PayrollSystem::updateEmployeeData(int id) {

    pair<Employee*, int> result = searchEmployeeById(id);
    Employee* emp = result.first;
    int attendance = result.second;
    cout << "What field you want to update? " << endl;
    cout << " 1. Update base salary. \n 2. update name \n 3. Update perks \n 4. update allowances. \n 5. update attendance\n " << endl;
    int n;
    cout << "ENTER THE CHOICE TO UPDATE:";
    cin >> n;
    string newname;
    double newBaseSalary;
    double newperks;
    double newallowances;
    if (emp != nullptr) {
        switch (n) {
        case 1:
            cout << "Enter the new salary : " << endl;
            cin >> newBaseSalary;
            emp->setBaseSalary(newBaseSalary);
            cout << "Employee with ID " << id << " data updated successfully." << endl;
            break;
        case 2:
                cout << "Enter the new name : " << endl;
                cin >> newname;
                emp->setupdatedNewname(newname);
                cout << "Employee with ID " << id << " data updated successfully." << endl;
                break;
        case 3:
            cout << "Enter Updates perks for the employee:  ";
            cin >> newperks;
            emp->setupdatesperks(newperks);
            cout << "Employee with ID " << id << " data updated successfully." << endl;
            break;
        case 4: 
            cout << "Enter Updates Allowances for the employee:  ";
            cin >> newallowances;
            emp->setupdatesallowances(newallowances);
            cout << "Employee with ID " << id << " data updated successfully." << endl;
            break;
        case 5:
            emp->setAtt();
            cout << "Employee with ID " << id << " data updated successfully." << endl;
            break;
        default:
            cout << "Enter valid field to enter." << endl;
            cout << "Employee with ID " << id << " not found." << endl;
            break;

        };
    }

}

//-------------------------------------------------------------------------------------------------------------------------//
//functions to update employee details 

void Employee::setupdatedNewname(string name)
{
    newname = name;
}

void Employee::setupdatesperks(double perks)
{
    newperks = perks;
}

void Employee::setupdatesallowances(double allowances)
{
    newallowances = allowances;
}



#endif
