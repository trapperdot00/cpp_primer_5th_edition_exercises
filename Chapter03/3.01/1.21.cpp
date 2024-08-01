#include "Sales_data.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

int main() {
	Sales_data data1;
	double price = 0.0;

	if (!(cin >> data1.bookNo >> data1.units_sold >> price)) {
		cerr << "No data?!" << endl;
		return -1;
	}
	data1.revenue = data1.units_sold * price;
	
	Sales_data data2;
	if (!(cin >> data2.bookNo >> data2.units_sold >> price)) {
		cerr << "No data?!" << endl;
		return -1;
	}
	data2.revenue = data2.units_sold * price;

	if (data1.bookNo == data2.bookNo) {
		unsigned total_units_sold = data1.units_sold + data2.units_sold;
		double total_revenue = data1.revenue + data2.revenue;
		double average_price = total_revenue / total_units_sold;
		cout << data1.bookNo << " " << total_units_sold << " " << total_revenue << " " << average_price << endl;
	} else {
		cerr << "Data must refer to the same ISBN" << endl;
		return -1;
	}
}

