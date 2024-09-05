#include "arr_size.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	int ia[10] = {}, ia2[12] = {};
	cout << arr_size(ia) << endl;
	cout << arr_size(ia2) << endl;
	return 0;
}
