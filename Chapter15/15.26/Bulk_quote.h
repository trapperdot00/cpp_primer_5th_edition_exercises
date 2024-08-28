#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <string>
#include <cstddef>
#include <utility>
#include <iostream>

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() : Disc_quote() {
		std::cout << "Bulk_quote default constructor" << std::endl;
	}
	Bulk_quote(const std::string &book, double price, std::size_t qty, double disc)
		: Disc_quote(book, price, qty, disc) {
		std::cout << "Bulk_quote constructor" << std::endl;
	}

	double net_price(std::size_t) const override;

	Bulk_quote(const Bulk_quote &b) : Disc_quote(b) {
		std::cout << "Bulk_quote copy constructor" << std::endl;
	}
	Bulk_quote(Bulk_quote &&b) noexcept : Disc_quote(std::move(b)) {
		std::cout << "Bulk_quote move constructor" << std::endl;
	}
	Bulk_quote &operator=(const Bulk_quote &rhs) {
		Disc_quote::operator=(rhs);
		std::cout << "Bulk_quote copy assignment operator" << std::endl;
		return *this;
	}
	Bulk_quote &operator=(Bulk_quote &&rhs) noexcept {
		Disc_quote::operator=(std::move(rhs));
		std::cout << "Bulk_quote move assignment operator" << std::endl;
		return *this;
	}
	~Bulk_quote() {
		std::cout << "Bulk_quote destructor" << std::endl;
	}
};

#endif
