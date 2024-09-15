#include "StrVec.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	StrVec svec;
	svec.emplace_back(3, 'a');
	svec.emplace_back("bbb");
	svec.emplace_back(std::string("ccc"));

	for (const std::string &s : svec)
		cout << s << endl;

	return 0;
}
