#include "Retail_quote.h"

#include <iostream>

int main() {
	Quote q("The Base Book", 19.99);
	Retail_quote rq("The Derived Book", 19.99, 10, 0.1);
	
	print_total(std::cout, q, 10);
	print_total(std::cout, rq, 10);

	print_total(std::cout, q, 20);
	print_total(std::cout, rq, 20);

	return 0;
}
