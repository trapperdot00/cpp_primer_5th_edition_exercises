#include "Sales_data.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main() {
	Sales_data total;	//	variable to hold data for the next transaction
	// read the first transaction and ensure that there are data to process
	double price, average_price;
	if (cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;	//	variable to hold the running sum
		//	read and process the remaining transactions
		while (cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			//	if we're still processing the same book
			if (total.bookNo == trans.bookNo) {
				//	update the running total
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			} else {
				//	print results for the previous book
				average_price = total.revenue / total.units_sold;
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << average_price << endl;
				//	total now refers to the next book
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		//	print the last transaction
		average_price = total.revenue / total.units_sold;
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << average_price << endl;
	} else {
		//	no input! warn the user
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
