#include "StrBlob.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	const StrBlob str( {"first string","second string","third string","fourth string"} );
	ConstStrBlobPtr pBeg = str.cbegin();
	StrBlob::size_type sz = str.size();
	for (StrBlob::size_type i = 0; i != sz; ++i) {
		cout << pBeg.deref() << endl;
		pBeg.incr();
	}
	return 0;
}
