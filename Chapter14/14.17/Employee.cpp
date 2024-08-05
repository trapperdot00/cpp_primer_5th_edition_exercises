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

Employee operator+(const Employee &lhs, unsigned rhs) {
	Employee ret = lhs;
	ret.age += rhs;
	return ret;
}

Employee operator+(const Employee &lhs, const Employee &rhs) {
	Employee ret = lhs;
	ret.age += rhs.age;
	return ret;
}

Employee operator-(const Employee &lhs, unsigned rhs) {
	Employee ret = lhs;
	ret.age -= rhs;
	return ret;
}

Employee operator-(const Employee &lhs, const Employee &rhs) {
	Employee ret = lhs;
	ret.age -= rhs.age;
	return ret;
}

bool operator==(const Employee &lhs, const Employee &rhs) {
	return lhs.name == rhs.name &&
			lhs.age == rhs.age &&
			lhs.rank == rhs.rank;
}

bool operator!=(const Employee &lhs, const Employee &rhs) {
	return !(lhs == rhs);
}
