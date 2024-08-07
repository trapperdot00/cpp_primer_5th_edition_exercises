#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cstddef>
#include <functional>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::istream_iterator;
using std::greater;
using std::bind;
using std::size_t;
using std::count_if;
using namespace std::placeholders;


int main() {
	cout << "Enter numbers: ";
	istream_iterator<int> in(cin), eof;
	vector<int> ivec(in, eof);

	size_t cnt = count_if(ivec.cbegin(), ivec.cend(), bind(greater<int>(), _1, 1024));

	cout << cnt << " elements greater than 1024" << endl;
	return 0;
}
