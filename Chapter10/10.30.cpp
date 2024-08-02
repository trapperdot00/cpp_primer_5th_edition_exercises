#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>

using std::ostream_iterator;
using std::istream_iterator;
using std::cout;
using std::cin;
using std::endl;
using std::copy;
using std::sort;
using std::vector;

int main() {
	vector<int> vec;
	istream_iterator<int> isIter(cin), eof;
	while (isIter != eof) {
		vec.push_back(*isIter++);
	}
	sort(vec.begin(), vec.end());
	ostream_iterator<int> outIter(cout, " ");
	copy(vec.cbegin(), vec.cend(), outIter);
	cout << endl;
	return 0;
}
