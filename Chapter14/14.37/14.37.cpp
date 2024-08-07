#include "Equal.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using std::replace_if;
using std::vector;
using std::for_each;
using std::cout;
using std::endl;
using std::cin;
using std::istream_iterator;

int main() {
	cout << "Enter numbers: ";
	// vector is initialized by the istream_iterator range: until standard input hits end-of-file
	istream_iterator<int> in(cin), eof;
	vector<int> ivec(in, eof);

	// print vector
	for_each(ivec.cbegin(), ivec.cend(), [](int i){ cout << i << ' '; });
	cout << endl;

	// value to get replaced
	int replaceThis = 13;
	// value to replace to
	int replaceTo = 42;

	// replace elements in vector
	replace_if(ivec.begin(), ivec.end(), Equal(replaceThis), replaceTo);

	// print vector
	for_each(ivec.cbegin(), ivec.cend(), [](int i){ cout << i << ' '; });
	cout << endl;
	return 0;
}
