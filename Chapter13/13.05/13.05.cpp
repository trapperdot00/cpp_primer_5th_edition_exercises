#include "13.05.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	HasPtr a("abc");
	HasPtr b(a);
	cout << "a: " << a.get() << endl;
	cout << "b: " << b.get() << endl;
	a.nullStr();
	cout << "a: " << a.get() << endl;
	cout << "b: " << b.get() << endl;
	return 0;
}
