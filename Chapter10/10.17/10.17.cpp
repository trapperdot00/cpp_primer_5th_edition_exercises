#include <iostream>
#include <algorithm>
#include <vector>
#include "Sales_data.h"
#include <sstream>

int main() {
	std::vector<Sales_data> vec;
	
	std::string line;
	while (std::getline(std::cin, line)) {
		std::istringstream stream(line);
		std::string name;
		unsigned units;
		double price;
		if (stream >> name >> units >> price) {
			vec.emplace_back(name, units, price);
		}
	}
	std::cout << "\nElements in vector:\n";
	std::for_each(vec.begin(), vec.end(), [](const Sales_data &elem) { print(std::cout, elem) << '\n'; });

	std::cout << "\nSorted elements:\n";
	std::sort(vec.begin(), vec.end(), [](const Sales_data &elem1, const Sales_data &elem2) -> bool { return elem1.isbn() < elem2.isbn(); });
	std::for_each(vec.begin(), vec.end(), [](const Sales_data &elem) { print(std::cout, elem) << '\n'; });

	return 0;
}
