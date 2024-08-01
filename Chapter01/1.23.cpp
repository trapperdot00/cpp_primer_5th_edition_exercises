#include "Sales_item.h"
#include <iostream>

int main() {
	Sales_item book1, book2;
	if (std::cin >> book1) {
		int cnt = 1;
		while (std::cin >> book2) {
			if (book1.isbn() == book2.isbn()) {
				++cnt;
			} else {
				std::cout << cnt << " transactions for ISBN " << book1.isbn() << std::endl;
				book1 = book2;
				cnt = 1;
			}
		}
		std::cout << cnt << " transactions for ISBN " << book1.isbn() << std::endl;
	}
	return 0;
}
