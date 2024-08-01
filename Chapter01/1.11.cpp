#include <iostream>

int main() {
	int num1, num2;
	std::cin >> num1 >> num2;
	while (num1 <= num2) {	// assuming the first inputted number is smaller than the second
		std::cout << num1 << std::endl;
		++num1;
	}
	return 0;
}
