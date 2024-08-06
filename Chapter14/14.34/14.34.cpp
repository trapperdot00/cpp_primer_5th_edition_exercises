#include "IfThenElse.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	IfThenElse obj;
	for (int i = 0; i != 20; ++i) {
		cout << obj(i % 2, i, i + 1) << endl;
	}
	return 0;
}
