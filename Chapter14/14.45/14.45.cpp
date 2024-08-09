#include "Sales_data.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
	Sales_data obj("bookNo", 10, 2);
	cout << static_cast<string>(obj) << ' ' << static_cast<double>(obj) << endl;
	return 0;
}
