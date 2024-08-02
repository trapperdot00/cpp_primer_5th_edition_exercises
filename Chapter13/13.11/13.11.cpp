#include "13.11.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
	HasPtr *p = new HasPtr("abc");
	cout << "p -> " << p->get() << endl;
	const string *sp = &(p->get());
	cout << "sp -> " << *sp << endl;
	delete p;
	p = nullptr;
	cout << "sp -> " << *sp << endl; // lol
	return 0;
}
