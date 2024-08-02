#include "Sales_data.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using std::istringstream;
using std::sort;
using std::cin;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::getline;

bool compareIsbn(const Sales_data &elem1, const Sales_data &elem2) {
	return elem1.isbn() < elem2.isbn();
}

int main() {
	vector<Sales_data> items;
	string line;
	while (getline(cin, line)) {
		string bookNo;
		unsigned units_sold;
		double price;
		istringstream stream(line);
		stream >> bookNo >> units_sold >> price;
		items.emplace(items.end(), bookNo, units_sold, price);
	}
	cout << '\n';
	sort(items.begin(), items.end(), compareIsbn);
	for (const Sales_data &elem : items) {
		print(cout, elem) << '\n';
	}
	return 0;
}
