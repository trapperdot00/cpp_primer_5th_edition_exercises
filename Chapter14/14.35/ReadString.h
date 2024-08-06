#ifndef READSTRING_H
#define READSTRING_H

#include <iostream>
#include <string>

class ReadString {
public:
	ReadString(std::istream &i = std::cin) : is(i) {}
	std::string operator()() const;
private:
	std::istream &is;
};

#endif
