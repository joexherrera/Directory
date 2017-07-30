#pragma once
#include <vector>
#include "Employee.h"

using namespace std;

class Directory
{
public:
	Directory();
	~Directory();

	void addEmp(Employee);
	Employee getEmp(int);

	void displayDirectory();
	Employee search(string);
	void remove(int);

	int size();

	void saveDir();

private:
	vector <Employee> vectorDir;
};