#include <iterator>
#include <cstddef>	// size_t and ptrdiff_t
#include <iostream>

using std::endl;
using std::cout;
using std::cin;
using std::begin;
using std::end;

int main() {
	constexpr size_t arrsize = 5;
	int ia[arrsize];
	int *p1 = ia, *p2 = ia + arrsize;
	int num;
	while (p1 != p2) {
		if (cin >> num) {
			*p1 = num;
			++p1;
		}
	}
	int *p3 = begin(ia);
	p1 += p3 - p1;	// p1 is at the end of the array
	while (p1 != p2) {
		cout << *p1 << " ";
		++p1;
	}
	cout << endl;
	return 0;
}
