#include "Employee.h"
#include <string>

//set & get Employee Category
void Employee::setCategory(string c)
{
	category = c;
}
string Employee::getCategory()
{
	return category;
}
//set & get Employee Name
void Employee::setName(string n)
{
	name = n;
}
string Employee::getName()
{
	return name;
}
//set & get Employee Id
void Employee::setId(int i)
{
	id = i;
}
int Employee::getId()
{
	return id;
}
void Employee::display()//function to display employee
{
	cout << "Name:\t" << getName() << endl;
	cout << "Type:\t" << getCategory() << endl;
	cout << "ID:\t" << getId() << endl;
}

void Employee::save()//save employee function
{
	cout << "Saving employee: " << endl << endl;
	cout << "\t" << getName() << endl;
	cout << "\t" << getCategory() << endl;
	cout << "\t" << getId() << endl;

}

ostream& operator<< (ostream& ofs, const Employee e)//overloading function ofstream
{
	ofs << e.name << endl;
	ofs << e.category << endl;
	ofs << e.id << endl;

	return ofs;
}

istream& operator>>(istream& ifs, Employee& e)
{
	getline(ifs, e.name); //string
	getline(ifs, e.category);//string
	ifs >> e.id;//string
	return ifs;
}