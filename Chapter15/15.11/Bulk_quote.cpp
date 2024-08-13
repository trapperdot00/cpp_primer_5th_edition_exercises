#include "Bulk_quote.h"

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
	Quote(book, p), min_qty(qty), discount(disc) {}

double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

std::ostream &Bulk_quote::debug(std::ostream &os) const {
	Quote::debug(os) << ' ';
	os << min_qty << ' ' << discount;
	return os;
}
