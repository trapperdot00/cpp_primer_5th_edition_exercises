#include <iostream>

int main() {
	int ival = 1.01; // valid: 1.01 truncates to 1
	// int &rval1 = 1.01;	// invalid: reference mustn't be bound to a literal, and the types don't match either
	int &rval2 = ival; // valid: refers to ival object, with value of 1
	// int &rval3;	// invalid: references must be initialized
	return 0;
}
