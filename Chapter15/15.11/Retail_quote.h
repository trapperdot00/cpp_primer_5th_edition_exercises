#ifndef RETAIL_QUOTE_H
#define RETAIL_QUOTE_H

#include <string>
#include <cstddef>
#include "Quote.h"

class Retail_quote : public Quote {
public:
	Retail_quote() = default;
	Retail_quote(const std::string &, double, std::size_t, double);
	double net_price(std::size_t) const override;

	std::ostream &debug(std::ostream &) const override;
private:
	std::size_t max_qty = 0;
	double discount = 0.0;
};

#endif
