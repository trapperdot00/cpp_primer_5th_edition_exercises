#include "StrBlob.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	StrBlob s( {"hi", "hello"} );
	cout << s.begin().deref() << endl << s.begin().incr().deref() << endl;
	return 0;
}
