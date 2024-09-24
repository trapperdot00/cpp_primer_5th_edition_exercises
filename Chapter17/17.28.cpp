#include <random>
#include <iostream>
#include <cstddef>

using std::default_random_engine;
using std::uniform_int_distribution;
using std::cout;
using std::endl;
using std::size_t;

unsigned getRandom() {
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u;
	return u(e);
}

int main() {
	for (size_t i = 0; i != 10; ++i) {
		cout << getRandom() << endl;
	}
	return 0;
}
