#include "Blob.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<int> ivec{0,1,2,3,4,5,6,7,8,9};
	Blob<int> iblob(ivec.cbegin(), ivec.cend());
	
	for (ConstBlobPtr<int> p = iblob.cbegin(); p != iblob.cend(); ++p)
		cout << *p << ' ';
	cout << endl;

	return 0;
}
