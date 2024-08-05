#include "Sales_data.h"

Sales_data &Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

// NONMEMBER FUNCTIONS

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

std::istream &operator>>(std::istream &is, Sales_data &item) {
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data ret = lhs;
	ret += rhs;
	return ret;
}
Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data ret = lhs;
	ret.units_sold -= rhs.units_sold;
	ret.revenue -= rhs.revenue;
	return ret;
}
Sales_data operator*(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data ret = lhs;
	ret.units_sold *= rhs.units_sold;
	ret.revenue *= rhs.revenue;
	return ret;
}
Sales_data operator/(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data ret = lhs;
	ret.units_sold /= rhs.units_sold;
	ret.revenue /= rhs.revenue;
	return ret;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data &Sales_data::operator=(const std::string &s) {
	bookNo = s;
	units_sold = 0;
	revenue = 0.0;
	return *this;
}
