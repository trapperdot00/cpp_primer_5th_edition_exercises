#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <cstddef>

class Employee {
	friend std::ostream &print(std::ostream &, const Employee &);

	static std::size_t currentID;
public:
	Employee();
	Employee(const std::string &);
private:
	std::string name;
	std::size_t id;
};

#endif
