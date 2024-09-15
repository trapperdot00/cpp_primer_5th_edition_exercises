#include "print.h"
#include "NoOutputOperator.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	NoOutputOperator obj("i have no output operator!!!");
	print(cout, obj);		// Since there is no output operator, our code won't compile
	return 0;
}
