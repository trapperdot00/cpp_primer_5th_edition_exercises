#include "Sales_item.h"
#include <iostream>

int main() {
	Sales_item book1, book2;
	if (std::cin >> book1 >> book2) {
		std::cout << book1 + book2 << std::endl;
	}
	return 0;
}
