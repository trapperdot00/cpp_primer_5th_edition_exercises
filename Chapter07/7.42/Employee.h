#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
	Employee(const std::string &n) : Employee(n, 18) {}
	Employee(const std::string &n, unsigned a) : Employee(n, a, "") {}
	Employee(const std::string &n, unsigned a, const std::string &r) : name(n), age(a), rank(r) {}
private:
	std::string name;
	unsigned age;
	std::string rank;
};

#endif
