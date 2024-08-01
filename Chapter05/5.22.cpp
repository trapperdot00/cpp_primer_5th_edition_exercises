#include <iostream>

int main() {
	int sz = -10;
	while (sz <= 0) {
		std::cout << sz << std::endl;
		++sz;
	}
	std::cout << sz << std::endl;
	return 0;
}
