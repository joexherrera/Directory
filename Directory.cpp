#pragma once
#include "Directory.h"
#include "Employee.h"

Directory::Directory()
{
}
Directory::~Directory()
{
}

//add employee to directory function
void Directory::addEmp(Employee e)
{
	vectorDir.push_back(e);
}
//return employee function
Employee Directory::getEmp(int pos)
{
	return vectorDir.at(pos);
}
//display directory function
void Directory::displayDirectory()
{
	Employee temp;
	for (unsigned i = 0; i < vectorDir.size(); i++)
	{
		getEmp(i).display();
		cout << endl;
	}
}
//search directory function
Employee Directory::search(string name)
{
	for (unsigned int i = 0; i < vectorDir.size(); i++)
	if (getEmp(i).getName() == name)
	{
		return vectorDir.at(i);
	}
	else
	{
		Employee notFound;
		notFound.setName("Not Found");
		return notFound;
	}
}
//remove employee function
void Directory::remove(int id)
{
	int pos = 0;
	for (unsigned int i = 0; i < vectorDir.size(); i++)
	if (vectorDir.at(i).getId() == id)
	{
		vectorDir.erase(vectorDir.begin() + pos);
		cout << "Employee removed." << endl << endl;
		break;
	}
	else
	{
		cout << "Employee not found.";
	}
}
//return size of directory function
int Directory::size()
{
	return vectorDir.size();
}
//save directory function
void Directory::saveDir()
{
	for (int i = 0; i < size(); i++)
		getEmp(i).save();
}