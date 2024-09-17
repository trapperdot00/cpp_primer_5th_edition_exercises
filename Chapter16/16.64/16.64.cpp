#include "count_val.h"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<const char *> cvec{"a", "b", "b", "b", "b", "c", "c", "d", "d", "d"};
	for (const char * const &p : cvec)
		cout << *p << ' ';
	cout << '\n' << "b occurs " << count_val(cvec, "b") << " times" << endl;
	return 0;
}
