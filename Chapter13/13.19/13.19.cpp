#include "Employee.h"

using std::cout;
using std::endl;

int main() {
	Employee e1, e2("user");
	print(cout, e1) << endl;
	print(cout, e2) << endl;
	Employee e3("user2");
	print(cout, e3) << endl;

	Employee e4 = e2;
	print(cout, e4) << endl;
	e4 = e3;
	print(cout, e4) << endl;

	return 0;
}
