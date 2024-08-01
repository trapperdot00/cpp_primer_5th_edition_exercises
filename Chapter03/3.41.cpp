#include <vector>
#include <iterator>	// begin and end functions for arrays, not vectors
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
	constexpr size_t arrsz = 10;
	int ia[arrsz];
	cout << "elements in array: ";
	for (int i = 0; i != arrsz; ++i) {
		ia[i] = i;
		cout << ia[i] << " ";
	}
	cout << endl;
	vector<int> ivec(begin(ia), end(ia));
	cout << "elements in ivec: ";
	for (const int &i : ivec) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
