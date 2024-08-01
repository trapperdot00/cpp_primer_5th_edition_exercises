#include <iostream>

int main() {
	int v1 = 0, v2 = 0;
	std::cout << "Enter two numbers: ";
	if (std::cin >> v1 >> v2) {
		if (v1 <= v2) {
			for (int i = v1; i <= v2; ++i) {
				std::cout << i << std::endl;			
			}
		} else {
			for (int i = v2; i <= v1; ++i) {
				std::cout << i << std::endl;
			}
		}
	}
	return 0;
}
