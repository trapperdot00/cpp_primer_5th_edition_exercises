#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
#include <functional>

class Sales_data;
	std::istream &read(std::istream&, Sales_data&);

class Sales_data {
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend Sales_data add(const Sales_data&, const Sales_data&);
	
	friend std::ostream &operator<<(std::ostream &, const Sales_data &);
	friend std::istream &operator>>(std::istream &, Sales_data &);

	friend Sales_data operator+(const Sales_data &, const Sales_data &);
	friend Sales_data operator-(const Sales_data &, const Sales_data &);
	friend Sales_data operator*(const Sales_data &, const Sales_data &);
	friend Sales_data operator/(const Sales_data &, const Sales_data &);

	friend bool operator==(const Sales_data &, const Sales_data &);

	friend struct std::hash<Sales_data>;
public:
	Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
		//std::cout << "mainConstructor" << std::endl;
	}
	Sales_data() : Sales_data("", 0, 0) {
		//std::cout << "empty" << std::endl;	
	}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
		//std::cout << "string" << std::endl;
	}
	Sales_data(std::istream &is) : Sales_data() {
		read(is, *this);
		//std::cout << "istream" << std::endl;
	}

	Sales_data &combine(const Sales_data&);
	std::string isbn() const { return bookNo; }
	
	Sales_data &operator+=(const Sales_data &);		// compound-assignment
	Sales_data &operator=(const std::string &);		// copy-assignment operator
	
	explicit operator std::string() const { return bookNo; }
	explicit operator double() const { return revenue; }
private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream &operator>>(std::istream &, Sales_data &);			// input operator
std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);

// inline and constexpr functions should be defined in the class headers
inline
double Sales_data::avg_price() const {
	return units_sold ? revenue / units_sold : 0;
}

namespace std {
template <>
struct hash<Sales_data> {
	typedef size_t result_type;
	typedef Sales_data argument_type;
	size_t operator()(const Sales_data &s) const {
		return hash<string>()(s.bookNo) ^
			   hash<unsigned>()(s.units_sold) ^
			   hash<double>()(s.revenue);
	}

	hash() = default;
	hash &operator=(const hash &) = default;
};
}

#endif
