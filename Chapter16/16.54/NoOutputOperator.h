#ifndef NOOUTPUTOPERATOR_H
#define NOOUTPUTOPERATOR_H

#include <string>

class NoOutputOperator {
public:
	NoOutputOperator(const std::string &s) : data(s) {}
private:
	std::string data;
};

#endif
