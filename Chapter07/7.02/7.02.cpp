#include "Sales_data.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	Sales_data data1, data2;
	data1.bookNo = "A";
	data1.units_sold = 12;
	data1.revenue = 36;

	data2.bookNo = "B";
	data2.units_sold = 5;
	data2.revenue = 30;

	cout << data1.isbn() << " " << data1.units_sold << " " << data1.revenue << endl;

	cout << data2.isbn() << " " << data2.units_sold << " " << data2.revenue << endl;
	data1.combine(data2);
	
	cout << data1.isbn() << " " << data1.units_sold << " " << data1.revenue << endl;
}
