#include "Quote.h"

int main() {
	Quote q("The Book of Wisdom", 39.99);
	print_total(std::cout, q, 3);
	return 0;
}
