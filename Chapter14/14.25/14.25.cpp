#include <iostream>
#include "Employee.h"

using std::cout;
using std::endl;

int main() {
	Employee a;
	cout << a << endl;
	a = {"employee", "22", "CEO"};
	cout << a << endl;
	return 0;
}
