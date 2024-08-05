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

Employee &Employee::operator=(const Employee &e) {
	name = e.name;
	age = e.age;
	rank = e.rank;
	return *this;
}

Employee &Employee::operator=(Employee &&e) noexcept {
	name = std::move(e.name);
	age = std::move(e.age);
	rank = std::move(e.rank);
	return *this;
}

Employee &Employee::operator=(const std::initializer_list<std::string> &il) {
	if (il.size() != 3)
		throw std::runtime_error("invalid size of initializer_list");
	std::initializer_list<std::string>::const_iterator it = il.begin();
	name = *it++;
	age = std::stoul(*it++);
	rank = *it;
	return *this;
}
