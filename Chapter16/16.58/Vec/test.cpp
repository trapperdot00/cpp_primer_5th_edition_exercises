#include "Vec.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
	Vec<string> svec;
	svec.emplace_back(3, 'a');
	svec.emplace_back("bbb");
	svec.emplace_back(string("ccc"));

	for (const string &s : svec)
		cout << s << endl;
	return 0;
}
