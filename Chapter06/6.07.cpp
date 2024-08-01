#include <iostream>
#include <cstddef>

int seq() {
	static size_t callCount = 0;
	return callCount++;
}

int main() {
	for (unsigned u = 0; u != 15; ++u)
		std::cout << seq() << std::endl;
	return 0;
}
