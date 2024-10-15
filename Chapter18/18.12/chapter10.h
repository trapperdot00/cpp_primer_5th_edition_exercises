#ifndef CHAPTER10_H
#define CHAPTER10_H

#include <string>
#include <iostream>

namespace cplusplus_primer {
namespace chapter10 {
	class Sales_data;
	std::istream &read(std::istream&, Sales_data&);

	class Sales_data {
		friend std::istream &read(std::istream &, Sales_data &);
		friend std::ostream &print(std::ostream &, const Sales_data &);
	public:
		Sales_data() : Sales_data("", 0, 0)
			{ std::cout << "Sales_data()" << std::endl; }
		Sales_data(const std::string &s) : Sales_data(s, 0, 0)
			{ std::cout << "Sales_data(const std::string &)" << std::endl; }
		Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n)
			{ std::cout << "Sales_data(const std::string &, unsigned, double)" << std::endl; }
		Sales_data(std::istream &is)
			{ std::cout << "Sales_data(std::istream &)" << std::endl; read(is, *this); }

		Sales_data &combine(const Sales_data&);
		std::string isbn() const { return bookNo; }
		inline double avg_price() const;

	private:
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
	};

	Sales_data add(const Sales_data&, const Sales_data&);
	std::ostream &print(std::ostream&, const Sales_data&);

	inline double Sales_data::avg_price() const {
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}
}
}

#endif
