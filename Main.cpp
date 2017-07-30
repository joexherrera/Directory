#pragma once
#include <iostream>
#include "Directory.h"
#include "Employee.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
	bool running = true; //used to initiate menu and quit program
	char choice;

	Directory dir;
	Employee temp;

	ofstream ofs("data.txt", ios::app); //output file stream with append
	ifstream ifs("data.txt");//input file stream


	cout << "Welcome to the Staff Directory" << endl << endl;

	while (running == true)//beginning of menu
	{
		cout << "Enter selection:\n [A]dd Employee\n [R]emove Employee\n [V]iew Directory\n [S]ave\n [E]xit\n >> ";
		cin >> choice;
		cin.ignore();//flushes input
		cout << endl;

		//beginning of if statement
		if (choice == 'A' || choice == 'a')// to add employee with corresponding category and ID
		{
			cout << "1. Please enter the name of the employee: ";//adding employee name
			string e;
			getline(cin, e);
			temp.setName(e);
			cin.ignore();

			cout << "2. Please enter employee category (Hourly, Commission, Salary): ";//adding employee category
			string c;
			cin >> c;
			temp.setCategory(c);
			cin.ignore();
			cout << endl;

			cout << "3. Please enter employee ID: ";//adding employee ID
			int i = 0;
			cin >> i;
			temp.setId(i);
			cin.ignore();
			cout << endl;

			dir.addEmp(temp);//adding employee & corresponding category and ID to directory
			ofs << dir.getEmp(0);	//saving employee			
		}
		else if (choice == 'R' || choice == 'r')//to remove employee
		{
			cout << "Please enter employee name: ";
			string name;
			Employee e;
			getline(cin, name);
			cin.ignore();
			e = dir.search(name);//feeding name entered above to search function and assigning result to "e"
			int pos = e.getId();// assigning ID from employee above to position
			dir.remove(pos); //removing employee entered above with remove function
		}
		else if (choice == 'V' || choice == 'v')//view directory
		{
			cout << "The directory currently has: " << dir.size() << " employee(s)" << endl;

			cout << "\nDisplaying Staff Directory" << endl;
			cout << "==========================\n" << endl;
			dir.displayDirectory(); //calling display function
		}
		else if (choice == 'S' || choice == 's')//save directory
		{
			ifstream ifs("data.txt"); // saving to data.txt
			Employee temp; 
			ifs >> temp;//saving employee 'temp'
			dir.addEmp(temp);
			cout << "...Save succesful." << endl;
		}
		else if (choice == 'E' || choice == 'e')//exit
			running = false;//boolean variable to exit program
		else
		{
			cout << "Invalid selection, please try again." << endl << endl; //choice validation
		}
	}
	system("pause");
}