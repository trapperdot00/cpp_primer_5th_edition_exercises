#include "HasPtr.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	HasPtr a("a");
	cout << a.use_count() << endl;
	{
		HasPtr b = a;
		cout << a.use_count() << '\t' << b.use_count() << endl;
	}
	cout << a.use_count() << endl;
	
	return 0;
}
