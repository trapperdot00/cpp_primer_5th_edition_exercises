#include "Debug.h"
#include <iostream>

using std::cerr;
using std::endl;

int main() {
	constexpr Debug io_sub(false, true, false);
	if (io_sub.any())
		cerr << "print appropriate error messages" << endl;
	constexpr Debug prod(false);
	if (prod.any())
		cerr << "print appropriate error messages" << endl;
	return 0;
}
