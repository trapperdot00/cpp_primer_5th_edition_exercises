#include <vector>
#include <iostream>
#include <functional>

#include "Sales_data.h"

using sditerator = std::vector<Sales_data>::iterator;
using const_sditerator = std::vector<Sales_data>::const_iterator;

sditerator first_greater(std::vector<Sales_data> &vec, double amount) {
	auto fcn = std::mem_fn(&Sales_data::avg_price);
	sditerator ret = vec.begin();
	while (ret != vec.end() && fcn(*ret) <= amount) {
		++ret;
	}
	return ret;
}
const_sditerator first_greater(const std::vector<Sales_data> &vec, double amount) {
	auto fcn = std::function<double (const Sales_data &)>(&Sales_data::avg_price);
	// auto fcn = std::bind(&Sales_data::avg_price, std::placeholders::_1);		// equivalent
	const_sditerator ret = vec.cbegin();
	while (ret != vec.cend() && fcn(*ret) <= amount) {
		++ret;
	}
	return ret;
}

int main() {
	std::vector<Sales_data> svec;
	const double amount = 20.0;

	std::istream &in = std::cin;
	Sales_data total;
	if (in >> total) {
		Sales_data trans;
		while (in >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans;
			} else {
				svec.push_back(total);
				total = trans;
			}
		}
		svec.push_back(total);
	}

	sditerator it;
	if ((it = first_greater(svec, amount)) != svec.end())
		std::cout << *it << "\tis the first Sales_data object with an average price greater than " << amount << std::endl;
	else
		std::cout << "There were no Sales_data object with an average price greater than " << amount << std::endl;

	return 0;
}
