#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <string>
#include <cstddef>
#include <utility>

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
	using Disc_quote::Disc_quote;

	double net_price(std::size_t) const override;
	Bulk_quote *clone() const & override	{ return new Bulk_quote(*this); }
	Bulk_quote *clone() && override 		{ return new Bulk_quote(std::move(*this)); }
};

#endif
