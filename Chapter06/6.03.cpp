#include <iostream>

int fact(int val) {
	int ret = 1;
	while (val > 1) {
		ret *= val--;
	}
	return ret;
}

int main() {
	std::cout << fact(5) << std::endl;
	return 0;
}
