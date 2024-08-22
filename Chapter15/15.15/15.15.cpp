#include "Bulk_quote.h"

int main() {
	Bulk_quote item("Big Book", 10, 5, 0.2);
	print_total(std::cout, item, 2);
	print_total(std::cout, item, 5);
	return 0;
}
