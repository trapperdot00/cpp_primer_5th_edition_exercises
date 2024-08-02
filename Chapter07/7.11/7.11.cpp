#include "Sales_data.h"
#include <iostream>

int main() {
	Sales_data data1, data2("data2"), data3("data3", 12, 3), data4(std::cin);
	print(print(print(print(std::cout, data1) << std::endl, data2) << std::endl, data3) << std::endl, data4) << std::endl;
	return 0;
}
