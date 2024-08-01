#include <iostream>

int main() {
	int i = 15, j = 30, *p = &i;
	p = &j;
	*p += 15;
	std::cout << i << " " << j << std::endl;
	return 0;
}
