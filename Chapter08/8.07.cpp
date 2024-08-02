#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::ofstream;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main(int argc, char **argv) {
	ifstream input(argv[1], ifstream::in);	// default settings
	ofstream output(argv[2], ofstream::out | ofstream::trunc);	// default settings
	if (input.fail() || output.fail()) return -1;
	Sales_data total;
	double price;
	if (input >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (input >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			} else {
				output << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << endl;
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		output << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << total.revenue / total.units_sold << endl;
	} else {
		std::cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
