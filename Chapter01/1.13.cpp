#include <iostream>

int main() {
	// 1.9
	int sum = 0;
	for (int val = 50; val <= 100; ++val) {
		sum += val;
	}
	std::cout << sum << std::endl;

	// 1.10
	for (int val = 10; val >= 0; --val) {
		std::cout << val << std::endl;
	}

	// 1.11
	std::cout << "Enter two numbers: ";
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	if (v1 <= v2)
		for (int val = v1; val <= v2; ++val) {
			std::cout << val << std::endl;
		}
	else
		for (int val = v2; val <= v1; ++val) {
			std::cout << val << std::endl;
		}
}
