#include "StrVec.h"

#include <iostream>

using std::cout;
using std::endl;
using std::size_t;

int main() {
	StrVec vec;

	cout << vec.size() << ' ' << vec.capacity() << endl;
	for (size_t i = 0; i != 24; ++i)
		vec.push_back("");
	cout << vec.size() << ' ' << vec.capacity() << endl;
	vec.reserve(50);
	cout << vec.size() << ' ' << vec.capacity() << endl;
	while (vec.size() != vec.capacity()) {
		vec.push_back("");
	}
	cout << vec.size() << ' ' << vec.capacity() << endl;
	vec.push_back("");
	cout << vec.size() << ' ' << vec.capacity() << endl;


	return 0;
}
