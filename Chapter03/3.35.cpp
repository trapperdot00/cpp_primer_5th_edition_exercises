#include <iterator>
#include <cstddef>	// size_t and ptrdiff_t
#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
	constexpr size_t arrsize = 10;
	int ia[arrsize] = {};
	for (const int &r : ia) {
		cout << r << " ";
	}
	cout << endl;

	for (int *p = begin(ia); p != end(ia); ++p) {
		*p = 2;
	}
	for (int *p = begin(ia); p != end(ia); ++p) {
		cout << *p << " ";
	}
	cout << endl;
	for (int *p = begin(ia); p != end(ia); ++p) {
		*p = 0;
		cout << *p << " ";
	}
	cout << endl;
	return 0;
}
