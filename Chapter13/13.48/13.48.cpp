#include "String.h"
#include <vector>
#include <cstddef>

using std::vector;
using std::cout;
using std::endl;
using std::size_t;

int main() {
	vector<String> vec;
	for (size_t i = 0; i != 16; ++i) {
		cout << "push_back " << i << endl;
		vec.push_back("hello");
		std::cout << endl;
	}
	return 0;
}
