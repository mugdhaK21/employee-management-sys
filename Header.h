#ifndef Header_h
#define header_h

//declare all tyhe classes i the header file

class Employee_management
{
private:
    // Variables for employee details
    //Master data
    char name[30];
    char id[5];
    char designation[10];
    int age, ctc;
    float perks;
    float allowances;
    float incentives;
    char experience[20];

    //TTransaction data: monthly attendance data (such that not to consider leaves, since it is not
    //considered in the scope)
    float attendance;


public:
    void menu();
    void waitForEnter();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
#endif
#pragma once
