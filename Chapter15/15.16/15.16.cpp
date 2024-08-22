#include "Retail_quote.h"

int main() {
	Retail_quote item("Limited book", 10, 5, 0.1);

	print_total(std::cout, item, 2);
	print_total(std::cout, item, 10);
	return 0;
}
