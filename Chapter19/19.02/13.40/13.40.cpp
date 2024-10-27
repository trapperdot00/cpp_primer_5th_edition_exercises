#include "StrVec.h"
#include <iostream>

std::ostream &print(std::ostream &os, const StrVec &vec) {
	std::string *p = vec.begin();
	while (p != vec.end())
		os << *p++ << ' ';
	return os;
}

using std::cout;
using std::endl;

int main() {
	StrVec vec({"asdf", "bvfa", "asdet", "hi", "okay"});
	print(cout, vec) << endl;
	return 0;
}
