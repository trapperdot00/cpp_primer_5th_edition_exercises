#ifndef SALES_EXCEPT_H
#define SALES_EXCEPT_H

#include <stdexcept>
#include <string>

class out_of_stock : public std::runtime_error {
public:
	explicit out_of_stock(const std::string &s) : std::runtime_error(s) {}
};

class isbn_mismatch : public std::logic_error {
public:
	explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}
	isbn_mismatch(const std::string &s, const std::string &l, const std::string &r)
		: std::logic_error(s), left(l), right(r) {}
	const std::string left, right;
};

#endif
