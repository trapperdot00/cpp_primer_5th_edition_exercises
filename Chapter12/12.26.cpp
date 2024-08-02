#include <memory>
#include <string>
#include <iostream>
#include <cstddef>

using std::size_t;
using std::allocator;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
	size_t n = 10;
	allocator<string> alloc;
	string *const p = alloc.allocate(n);
	string s;
	string *q = p;
	while (q != p + n && cin >> s) {
		alloc.construct(q++, s);
	}
	const size_t readSize = q - p;
	cout << "size: " << readSize << endl;
	for (const string *sp = p; sp != q; ++sp) {
		cout << *sp << endl;
	}
	while (q != p) {
		alloc.destroy(--q);
	}
	alloc.deallocate(p, n);
	return 0;
}
