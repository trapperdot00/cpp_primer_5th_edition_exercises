#include "Retail_quote.h"

Retail_quote::Retail_quote(const std::string &book, double p, std::size_t n, double disc) : 
	Quote(book, p), max_qty(n), discount(disc) {}

double Retail_quote::net_price(std::size_t cnt) const {
	if (cnt <= max_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
