#include <cstddef>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	constexpr size_t arrsize = 10;
	int ia[arrsize];
	for (size_t index = 0; index != arrsize; ++index) {
		ia[index] = index;
	}
	vector<int> copied;
	for (int i : ia) {
		copied.push_back(i);
	}
	for (const int &r : copied) {
		cout << r << " ";
	}
	cout << endl;
	return 0;
}
