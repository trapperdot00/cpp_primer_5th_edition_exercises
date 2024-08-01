#include <iostream>

int main() {
	int i = 42;
	int *p1 = &i;
	*p1 = *p1 * *p1; // the same as "i = i * i" or "i *= i"
	std::cout << *p1 << " " << i << std::endl;
	return 0;
}
