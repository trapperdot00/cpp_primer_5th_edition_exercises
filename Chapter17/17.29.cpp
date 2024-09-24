#include <random>
#include <iostream>
#include <cstddef>

using std::default_random_engine;
using std::uniform_int_distribution;
using std::cout;
using std::endl;
using std::size_t;

unsigned getRandom(size_t seed = 0) {
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u;
	if (seed)
		e.seed(seed);
	return u(e);
}

int main() {
	cout << getRandom(120) << endl;
	for (size_t i = 0; i != 9; ++i)
		cout << getRandom() << endl;

	cout << '\n' << getRandom(120) << endl;
	for (size_t i = 0; i != 9; ++i)
		cout << getRandom() << endl;
	return 0;
}
