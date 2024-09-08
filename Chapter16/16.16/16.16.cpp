#include "Vec.h"

#include <iostream>
#include <string>

using StrVec = Vec<std::string>;

using std::cout;
using std::endl;
using std::cin;
using std::string;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vec<T> &v) {
	for (const T *p = v.cbegin(); p != v.cend(); ++p)
		os << *p << ' ';
	return os;
}

int main() {
	Vec<int> ivec{0,1,2,3,4,5,6,7,8,9};
	cout << ivec << endl;
	StrVec svec;
	for (string temp; cin >> temp; svec.push_back(temp))
		cout << svec.size() << "\t:\t" << svec.capacity() << endl;
	cout << svec << endl;
	return 0;
}
