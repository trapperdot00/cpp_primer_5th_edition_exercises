#ifndef PRINTSTRING_H
#define PRINTSTRING_H

#include <iostream>
#include <string>

class PrintString {
public:
	PrintString(std::ostream &o, char c) : os(o), sep(c) {}
	void operator()(const std::string &s) const
		{ os << s << sep; }
private:
	std::ostream &os;
	char sep;
};

#endif
