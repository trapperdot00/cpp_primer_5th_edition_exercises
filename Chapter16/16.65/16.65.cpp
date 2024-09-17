#include "debug_rep.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	char carr[] = "helloooo!";
	char *cp = carr;
	const char *ccp = carr;
	
	cout << debug_rep(carr) << endl;
	cout << debug_rep(cp) << endl;
	cout << debug_rep(ccp) << endl;
	return 0;
}
