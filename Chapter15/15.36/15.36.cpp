#include <iostream>

#include "Query.h"

using std::cout;
using std::endl;

int main() {
	cout << "Constructors executed in the processing of the expression:\n" << endl;
	Query q = Query("fiery") & Query("bird") | Query("wind");

	cout << "\n\ncalls to rep:\n" << endl;
	cout << q << endl;
	return 0;
}
