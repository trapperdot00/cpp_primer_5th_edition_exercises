#include <cstddef>	// size_t
#include <iostream>

using std::cout;
using std::endl;

int main() {
	constexpr size_t arrsize = 10;
	int ia[arrsize];
	for (size_t index = 0; index != arrsize; ++index) {
		ia[index] = index;
	}
	int copied[arrsize];
	for (size_t index = 0; index != arrsize; ++index) {
		copied[index] = ia[index];
		cout << copied[index] << " ";
	}
	cout << endl;
	return 0;
}
