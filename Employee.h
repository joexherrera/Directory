#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee
{
public:
	void setName(string);
	string getName();

	void setCategory(string);
	string getCategory();

	void setId(int);
	int getId();

	void display();

	void save();

	friend ostream& operator<<(ostream&, const Employee); //file save
	friend istream& operator>>(istream&, Employee&);

private:
	string name;
	string category;
	int id;
};