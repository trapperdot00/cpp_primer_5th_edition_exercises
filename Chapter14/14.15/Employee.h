#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
	friend std::ostream &operator<<(std::ostream &, const Employee &);
	friend std::istream &operator>>(std::istream &, Employee &);

	friend Employee operator+(const Employee &, unsigned);
	friend Employee operator-(const Employee &, unsigned);
	
	friend Employee operator+(const Employee &, const Employee &);
	friend Employee operator-(const Employee &, const Employee &);
public:
	Employee(const std::string &n = "") : name(n) {}
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

Employee operator+(const Employee &, unsigned);		// add to employee's age
Employee operator-(const Employee &, unsigned);		// subtract from employee's age

Employee operator+(const Employee &, const Employee &);
Employee operator-(const Employee &, const Employee &);

bool operator==(const Employee &, const Employee &);	// check for equality in each member ANDed
bool operator!=(const Employee &, const Employee &);	// check for inequality in each member ANDed

std::ostream &operator<<(std::ostream &, const Employee &);
std::istream &operator>>(std::istream &, Employee &);

#endif
