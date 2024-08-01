#include <iostream>
#include <stdexcept>

int absolute(int val) {
	if (val >= 0) 
		return val;
	return val * -1;
}

int main() {
	std::cout << "Enter number: ";
	int num;
	try {
		if (!(std::cin >> num))
			throw std::runtime_error("Invalid input!");
		std::cout << "Absolute value: " << absolute(num) << std::endl;
	} catch (std::runtime_error err) {
			std::cout << err.what() << std::endl;
	}
	return 0;
}
