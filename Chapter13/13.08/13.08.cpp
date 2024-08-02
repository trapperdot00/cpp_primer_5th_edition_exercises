#include "13.08.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	HasPtr a("abc"), b("def");	// CALLS CONSTRUCTOR THAT TAKES A STRING
	cout << "a: " << a.get() << "\nb: " << b.get() << '\n';
	HasPtr c = a;				// USES THE COPY CONSTRUCTOR
	cout << "c: " << c.get() << "\tCopy Constructor\n";
	c = b;						// USES THE COPY-ASSIGNMENT OPERATOR
	cout << "c: " << c.get() << "\tCopy-Assignment Operator" << endl;
	return 0;
}
