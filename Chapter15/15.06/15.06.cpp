#include "Bulk_quote.h"

int main() {
	Quote q("The Base Book", 15.99);
	Bulk_quote b("The Derived Book", 25.99, 5, 0.1);

	print_total(std::cout, q, 2);
	print_total(std::cout, q, 10);

	print_total(std::cout, b, 2);
	print_total(std::cout, b, 10);

	return 0;
}
