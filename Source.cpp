#ifndef Source_CPP
#define Source_CPP
#include<iostream>
#include<cstring>
#include "Header.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

Attendance::Attendance() {

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


//int Attendance::getEmployeeId() const {
//    return employeeId;
//}

void Attendance::setDaysPresent() {
    int d;
    cout << "Enter the days the employee was present: " << endl;
    cin >> d;
    daysPresent = d;
}

int Attendance::getDaysPresent() const {
    return daysPresent;
}
void Attendance::setAttendance() {
    cout << "TOTAL WORKING DAYS: " << endl;
    cin >> total_workingdays;

    attendance =(float)daysPresent / total_workingdays * 100;
   
}

int Attendance::getAttendance()  {
    return attendance;
}

//void Attendance::displayAttendance()
//{
//    int totalattendance;
//    cout << "TOTAL WORKING DAYS: " << endl;
//    cin >> total_workingdays;
//
//    totalattendance = (daysPresent / total_workingdays) * 100;
//    cout << "TOTAL ATTENDANCE" << totalattendance;
//}

//------------------------------------------------------------------------------------------//
void PayrollSystem::addEmployee(Employee* emp)
{
    employees.push_back(emp);
}

//void PayrollSystem::addAttendanceRecord(int employeeId, int daysPresent) {
  //  attendanceRecords.emplace_back(employeeId, daysPresent);
//}

void PayrollSystem::displayAllEmployees() const
{
    vector<Employee*> sortedEmployees = employees;
    sort(sortedEmployees.begin(), sortedEmployees.end(), [](Employee* a, Employee* b) {
        return a->calculateSalary() > b->calculateSalary();
        });

    for (Employee* emp : sortedEmployees) {
        emp->display();
        cout << "Attendance: ";
        cout<<emp->getEAtt();
        //auto it = find_if(attendanceRecords.begin(), attendanceRecords.end(), [emp](const Attendance& att) {
        //    return att.getEmployeeId() == emp->getEmployeeId();
        //    });
        //if (it != attendanceRecords.end()) {
        //    cout << it->getDaysPresent() << " days present this month." << endl;
        //    //cout << it->displayAttendance() << " days present this month." << endl;
        //}
        //else {
        //    cout << "Attendance not recorded for this employee." << endl;
        //}
    }
}

Employee* PayrollSystem::searchEmployeeById(int id) const {
    for (Employee* emp : employees) {
        if (emp->getEmployeeId() == id) {
            return emp;
        }
    }
    return nullptr;
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
    Employee* emp = searchEmployeeById(id);
    cout << "What field you want to update? " << endl;
    cout << " 1. Update base salary. \n 2. update name \n 3. Update perks \n 4. update allowances. \n 5. update attendance\n " << endl;
    int n;
    cin >> n;

    if (emp != nullptr) {
        switch (n) {
        case 1:
            cout << "Enter the new salary : " << endl;
            double newBaseSalary;
            cin >> newBaseSalary;
            emp->setBaseSalary(newBaseSalary);
            cout << "Employee with ID " << id << " data updated successfully." << endl;
        /*case 2:
            cout << "Enter the new name : " << endl;
            string newname;
            cin >> newname;
            emp->setupdatedNewname(newname);
            cout << "Employee with ID " << id << " data updated successfully." << endl;*/
        case 3:
            double newperks;
            cout << "Enter Updates perks for the employee:  ";
            cin >> newperks;
            emp->setupdatesperks(newperks);
            cout << "Employee with ID " << id << " data updated successfully." << endl;
        case 4:
            double newallowances;
            cout << "Enter Updates Allowances for the employee:  ";
            cin >> newallowances;
            emp->setupdatesallowances(newallowances);
            cout << "Employee with ID " << id << " data updated successfully." << endl;
        case 5:
            emp->setAtt();
            cout << "Employee with ID " << id << " data updated successfully." << endl;
        default:
            cout << "Enter valid field to enter." << endl;
            cout << "Employee with ID " << id << " not found." << endl;

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
