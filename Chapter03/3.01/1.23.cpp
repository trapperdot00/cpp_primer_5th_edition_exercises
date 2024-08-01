#include "Sales_data.h"
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
	Sales_data data1, data2;
	double price;
	if (!(cin >> data1.bookNo >> data1.units_sold >> price)) {
		cerr << "No data?!" << endl;
		return -1;
	}
	data1.revenue = data1.units_sold * price;
	unsigned cnt = 1;
	while (cin >> data2.bookNo >> data2.units_sold >> price) {
		data2.revenue = data2.units_sold * price;
		if (data1.bookNo == data2.bookNo) {
			++cnt;
		} else {
			cout << cnt << " transactions for ISBN " << data1.bookNo << endl;

			data1.bookNo = data2.bookNo;
			data1.units_sold = data2.units_sold;
			data1.revenue = data2.revenue;

			cnt = 1;
		}

	}
	cout << cnt << " transactions for ISBN " << data1.bookNo << endl;


	return 0;
}
