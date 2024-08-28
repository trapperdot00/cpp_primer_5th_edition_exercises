#ifndef BASKET_H
#define BASKET_H

#include "Quote.h"

#include <iostream>
#include <memory>
#include <set>

class Basket {
public:
	// "old" method that takes a shared_ptr
	void add_item(const std::shared_ptr<Quote> &sale) {
		items.insert(sale);
	}
	// methods that manage memory allocation instead of the user
	void add_item(const Quote &sale) {
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote &&sale)	{
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}
	
	double total_receipt(std::ostream &) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif
