#include <iostream>
#include <cstddef>	// size_t type

using std::endl;
using std::cout;

int main() {
	constexpr size_t arrsize = 10;
	int ia[arrsize]; // elements have undefined values, since uninitialized ints are undefined inside functions
	for (size_t index = 0; index != arrsize; ++index) {
		ia[index] = index;
		cout << ia[index] << " ";
	}
	cout << endl;
	return 0;
}
