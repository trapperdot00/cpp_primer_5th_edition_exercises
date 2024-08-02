#include "13.13.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

const X &nonsenseRef(const X& a) {
	return a;
}

const X nonsenseCopy(const X a) {
	return a;
}

int main() {
	cout << "X obj1; ";
	X obj1;
	cout << "\nX obj2(obj1); ";
	X obj2(obj1);
	cout << "\nX obj3 = obj2; ";
	X obj3 = obj2;
	cout << "\nobj1 = obj2; ";
	obj1 = obj2;
	cout << "\nnonsenseRef(obj1); ";
	nonsenseRef(obj1);
	cout << "\nnonsenseCopy(obj2); ";
	nonsenseCopy(obj2);
	cout << "\nX *p = new X; ";
	X *p = new X;
	cout << "\ndelete p; ";
	delete p;
	cout << "\nreturn 0; ";
	return 0;
}
