#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::unique_copy;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::sort;

int main() {
	istream_iterator<int> isiter(cin), eof;
	vector<int> vec(isiter, eof);
	sort(vec.begin(), vec.end());
	ostream_iterator<int> outiter(cout, " ");
	unique_copy(vec.cbegin(), vec.cend(), outiter);
	cout << endl;
	return 0;
}
