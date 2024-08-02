#include "Employee.h"

std::ostream &operator<<(std::ostream &os, const Employee &e) {
	os << e.name << " " << e.age << " " << e.rank;
	return os;
}

std::istream &operator>>(std::istream &is, Employee &e) {
	is >> e.name >> e.age >> e.rank;
	if (!is)
		e = Employee();
	return is;
}
