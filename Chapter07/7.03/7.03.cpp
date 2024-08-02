#include <string>
#include <iostream>
#include "Sales_data.h"

int main() {
	Sales_data total;
	double price;
	if (std::cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				std::cout << total.isbn() << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << std::endl;
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		std::cout << total.isbn() << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << std::endl;
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
