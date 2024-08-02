#include "Sales_data.h"

int main() {
	Sales_data total(std::cin);
	if (std::cin) {
		Sales_data trans(std::cin);
		while (std::cin) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(std::cout, total) << std::endl;
				total = trans;
			}
			read(std::cin, trans);
		}
		print(std::cout, total) << std::endl;
	} else {
		std::cerr << "No data?!" << std::endl;
	}
	return 0;
}
