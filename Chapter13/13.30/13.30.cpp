#include "HasPtr.h"

int main() {
	HasPtr a("string1");
	HasPtr b = a;
	HasPtr c("string2");
	b = c;	// calls swap
	return 0;
}
