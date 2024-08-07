#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::istream_iterator;
using std::transform;
using std::bind;
using namespace std::placeholders;
using std::multiplies;
using std::for_each;

int main() {
	cout << "Enter numbers: ";
	istream_iterator<int> in(cin), eof;
	vector<int> ivec(in, eof);

	transform(ivec.begin(), ivec.end(), ivec.begin(),  bind(multiplies<int>(), _1, 2));

	for_each(ivec.cbegin(), ivec.cend(), [](int i){ cout << i << ' '; });
	cout << endl;
	return 0;
}
