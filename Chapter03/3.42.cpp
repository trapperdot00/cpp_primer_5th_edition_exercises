#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main() {
	constexpr size_t sz = 11;
	vector<int> ivec;
	for (unsigned u = 0; u != sz; ++u) {
		ivec.push_back(u);
	}
	cout << "elements in ivec: ";
	for (const int &i : ivec) {
		cout << i << " ";
	}
	cout << endl;

	int ia[sz];
	cout << "elements in ia: ";
	for (size_t idx = 0; idx != sz; ++idx) {
		ia[idx] = ivec[idx];
		cout << ia[idx] << " ";
	}
	cout << endl;
	return 0;
}
