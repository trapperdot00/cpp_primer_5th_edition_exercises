#include <iostream>

void cFact() {
	int val;
	std::cout << "Enter number to generate its factorial: ";
	if (!(std::cin >> val)) { return; }
	int fact = 1;
	while (val > 1)
		fact *= val--;
	std::cout << "Factorial: " << fact << std::endl;
}

int main() {
	cFact();
	return 0;
}
