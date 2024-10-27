#include "StrVec.h"

#include <iostream>

using std::cout;
using std::endl;
using std::size_t;

std::ostream &print(std::ostream &os, const StrVec &vec) {
	for (std::string *p = vec.begin(); p != vec.end(); ++p) {
		os << *p << ' ';
	}
	return os;
}

int main() {
	StrVec vec;
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;
	vec.resize(10);
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;
	print(cout, vec) << endl;
	vec.resize(20, "a");
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;
	print(cout, vec) << endl;
	vec.resize(15);
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;
	print(cout, vec) << endl;
	return 0;
}
