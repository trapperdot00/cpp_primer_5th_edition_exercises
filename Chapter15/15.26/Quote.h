#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <cstddef>
#include <iostream>
#include <utility>

class Quote {
public:
	Quote() : bookNo(""), price(0.0) {
		std::cout << "Quote default constructor" << std::endl;
	}
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {
		std::cout << "Quote constructor" << std::endl;
	}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ~Quote() {
		std::cout << "Quote destructor" << std::endl;
	}
	
	Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
		std::cout << "Quote copy constructor" << std::endl;
	}
	Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
		std::cout << "Quote move constructor" << std::endl;
	}
	Quote &operator=(const Quote &rhs) {
		std::cout << "Quote copy assignment operator" << std::endl;
		bookNo = rhs.bookNo;
		price = rhs.price;
		return *this;
	}
	Quote &operator=(Quote &&rhs) noexcept {
		std::cout << "Quote move assignment operator" << std::endl;
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}

	virtual std::ostream &debug(std::ostream &) const;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

double print_total(std::ostream &, const Quote &, std::size_t);

#endif
