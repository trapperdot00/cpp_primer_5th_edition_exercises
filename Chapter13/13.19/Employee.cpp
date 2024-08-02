#include "Employee.h"

std::size_t Employee::currentID = 0;

Employee::Employee() : id(currentID++) {}
Employee::Employee(const std::string &n) : name(n), id(currentID++) {}

Employee::Employee(const Employee &e) : name(e.name), id(currentID++) {}
Employee &Employee::operator=(const Employee &e) {
	name = e.name;
	return *this;
}

std::ostream &print(std::ostream &os, const Employee &e) {
	os << e.name << ' ' << e.id;
	return os;
}
