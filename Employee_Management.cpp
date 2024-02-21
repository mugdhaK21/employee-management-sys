// main file for cppp
// menu will be here
//Include All Header files.
#include <iostream>
#include <windows.h>
//#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "Header.h"


using namespace std;

void truncateFile(const string& filename) {
    ofstream file(filename, ios::trunc); // Opens the file and truncates it
    if (!file) {
        cerr << "Error truncating file." << endl;
        return;
    }

    file.close();
}


int main()
{
	Employee_management Emp1;
	Emp1.menu();
	//truncateFile("record.txt");
	return 0;
}

