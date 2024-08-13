#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <string>
#include <cstddef>

#include "Quote.h"

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &, double, std::size_t, double);
	double net_price(std::size_t) const override;

	std::ostream &debug(std::ostream &) const override;
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

#endif
