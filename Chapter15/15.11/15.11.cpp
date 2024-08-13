#include "Bulk_quote.h"
#include "Retail_quote.h"

int main() {
	Quote q("Base", 11.23);
	Bulk_quote b("Bulk", 22.34, 5, 0.10);
	Retail_quote r("Retail", 33.12, 10, 0.15);
	q.debug(std::cout) << std::endl;
	b.debug(std::cout) << std::endl;
	r.debug(std::cout) << std::endl;
	return 0;
}
