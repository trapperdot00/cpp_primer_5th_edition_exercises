#include "Sales_data.h"
#include <iostream>

using std::cerr;
using std::endl;

int main() {
	Sales_data item1("135135", 6, 25), item2("163642", 2, 15.59);
	try {
		item1 + item2;
	} catch (const isbn_mismatch &e) {
		cerr << e.what() << ":\t" << e.left << " - " << e.right << endl;
	}
	return 0;
}
