#include "Sales_data.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::cin;
using std::endl;

int main() {
	Sales_data total, data;
	double price;
	if (!(cin >> total.bookNo >> total.units_sold >> price)) {
		cerr << "No data?!" << endl;
		return -1;
	}
	total.revenue = total.units_sold * price;

	while (cin >> data.bookNo >> data.units_sold >> price) {
		data.revenue = data.units_sold * price;
		
		total.bookNo = "";
		total.units_sold += data.units_sold;
		total.revenue += data.revenue;
	}

	double average_price = total.revenue / total.units_sold;
	cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << average_price << endl;

	return 0;
}
