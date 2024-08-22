#include "Square.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	Square s(15);
	cout << "Square's sides' length: " << s.length() << 
			"\nPerimeter: " << s.perimeter() <<
			"\nArea: " << s.area() << endl;
	printCenter(cout, s) << endl;

	s.moveDelta(10, -20);
	printCenter(cout, s) << endl;

	s.center();
	printCenter(cout, s) << endl;
	return 0;
}
