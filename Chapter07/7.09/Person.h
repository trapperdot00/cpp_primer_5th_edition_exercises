#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

struct Person {
	std::string getName() const { return name; }
	std::string getAddress() const { return address; }

	std::string name;
	std::string address;
};

std::istream &read(std::istream &, Person &);
std::ostream &print(std::ostream &, const Person &);
#endif
