#ifndef RETAIL_QUOTE_H
#define RETAIL_QUOTE_H

#include <string>
#include <cstddef>

#include "Disc_quote.h"

class Retail_quote : public Disc_quote {
public:
	Retail_quote() = default;
	Retail_quote(const std::string &book, double price, std::size_t qty, double disc)
		: Disc_quote(book, price, qty, disc) {}

	double net_price(std::size_t) const override;
};

#endif
