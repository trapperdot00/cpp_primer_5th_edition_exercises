#include "Bulk_quote.h"

double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
