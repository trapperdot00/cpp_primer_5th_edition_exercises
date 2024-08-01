#include <vector>
#include <iostream>
#include <cstddef>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> ivec;
	cout << "ivec elements: ";
	for (size_t i = 0; i != 25; ++i) {
		ivec.push_back(i);
		cout << i << " ";
	}
	cout << endl;
	cout << "elements after change: ";
	for (int &i : ivec) {
		i = (i % 2 == 1) ? i * 2 : i;
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
