#include "Basket.h"

double Basket::total_receipt(std::ostream &os) const {
	double sum = 0.0;
	for (std::multiset<std::shared_ptr<Quote>, decltype(compare)*>::const_iterator iter = items.cbegin(); 
			iter != items.cend();
			iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}
