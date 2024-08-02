#include "String.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {
	String s("hello!");
	String s2 = s;
	print(cout, s) << endl;
	print(cout, s2) << endl;
	String s3("what");
	s2 = s3;
	print(cout, s2) << endl;
	
	String s4;
	for (const char *p = s.cbegin(); p != s.cend(); ++p) {
		s4.push_back(*p);
		cout << s4.size() << '\t' << s4.capacity() << endl;
		print(cout, s4) << endl;
	}
	return 0;
}
