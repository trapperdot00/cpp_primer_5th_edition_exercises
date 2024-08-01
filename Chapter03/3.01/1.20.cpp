#include "Sales_data.h"
#include <iostream>

using std::endl;
using std::cin;
using std::cout;
using std::cerr;

int main() {
	Sales_data data;
	double price;
	if (!(cin >> data.bookNo >> data.units_sold >> price)) {
		cerr << "No data?!" << endl;
		return -1;
	}
	
	data.revenue = data.units_sold * price;
	double average_price = data.revenue / data.units_sold;
	cout << data.bookNo << " " << data.units_sold << " " << data.revenue << " " << average_price << endl;

	while (cin >> data.bookNo >> data.units_sold >> price) {
		data.revenue = data.units_sold * price;
		average_price = data.revenue / data.units_sold;
		cout << data.bookNo << " " << data.units_sold << " " << data.revenue << " " << average_price << endl;
	}

	return 0;
}
