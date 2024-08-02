#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
	Employee(const std::string &n) : name(n) {}
	Employee(const std::string &n, unsigned a) : name(n), age(a) {}

	Employee operator++();	// increment employee's age by one
	Employee operator--();	// decrement employee's age by one
	Employee &operator+=(unsigned);	// change employee's age
	Employee &operator-=(unsigned);	// change employee's age
private:
	std::string name;
	unsigned age;
	std::string rank;
};

Employee operator+(Employee, unsigned);		// add to employee's age
Employee operator-(Employee, unsigned);		// subtract from employee's age

bool operator==(const Employee &, const Employee &);	// check for equality in each member ANDed
bool operator!=(const Employee &, const Employee &);	// check for inequality in each member ANDed

#endif
