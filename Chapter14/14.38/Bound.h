#ifndef BOUND_H
#define BOUND_H

#include <string>

class Bound {
public:
	Bound(std::string::size_type n) : max_length(n) {}
	bool operator()(const std::string &) const;
private:
	std::string::size_type max_length;
};

#endif
