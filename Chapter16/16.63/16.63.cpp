#include "count_val.h"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
	vector<double> dvec{1.1, 1.2, 1.2, 1.2, 1.3, 1.3, 1.4, 1.5, 1.6, 1.7};
	vector<int> ivec{1, 2, 2, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 0};
	vector<string> svec{"a", "b", "b", "b", "b", "c", "c"};

	cout << count_val(dvec, 1.2) << endl;
	cout << count_val(ivec, 2) << endl;
	cout << count_val(svec, string("b")) << endl;
	return 0;
}
