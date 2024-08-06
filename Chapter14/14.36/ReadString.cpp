#include "ReadString.h"

std::string ReadString::operator()() const {
	std::string line;
	std::getline(is, line);
	if (!is)
		return std::string();
	return line;
}
