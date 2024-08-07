#ifndef SIZECOMP_H
#define SIZECOMP_H

#include <string>
#include <vector>

class SizeComp {
public:
	SizeComp(std::vector<std::string>::size_type n) : sz(n) {}
	bool operator()(const std::string &a) const
		{ return a.size() >= sz; }
private:
	std::vector<std::string>::size_type sz;
};

#endif
