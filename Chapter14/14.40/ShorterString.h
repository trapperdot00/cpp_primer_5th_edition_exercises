#ifndef SHORTERSTRING_H
#define SHORTERSTRING_H

#include <string>

struct ShorterString {
	bool operator()(const std::string &a, const std::string &b) const
		{ return a.size() < b.size(); }
};

#endif
