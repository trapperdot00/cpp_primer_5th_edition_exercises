#include <iostream>
#include "Sales_data.h"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Add argument for previous exercise (1.20/1.21/1.22/1.23)" << std::endl;	
		return -1;
	}
	std::string exc = argv[1];
	if (exc == "1.20") {
		// 1.20
		Sales_data data1;
		double price = 0.0;
		while (std::cin >> data1.bookNo >> data1.units_sold >> price) {
			data1.revenue = data1.units_sold * price;
			std::cout << data1.bookNo << " " << data1.units_sold << " " << data1.revenue << " " << price << std::endl;
		}
	} else if (exc == "1.21") {
		// 1.21
		Sales_data data1;
		double price = 0.0;
		if (std::cin >> data1.bookNo >> data1.units_sold >> price) {
			data1.revenue = data1.units_sold * price;
			unsigned totalCnt = data1.units_sold;
			double totalRevenue = data1.revenue;
			Sales_data data2;
			if (std::cin >> data2.bookNo >> data2.units_sold >> price) {
				data2.revenue = data2.units_sold * price;
				totalCnt += data2.units_sold;
				totalRevenue += data2.revenue;
				double avg = totalRevenue / totalCnt;
				if (data1.bookNo == data2.bookNo) {
					std::cout << data1.bookNo << " " << data1.units_sold + data2.units_sold << " " << data1.revenue + data2.revenue << " " << avg << std::endl;
				}
			}
		}
	} else if (exc == "1.22") {
		// 1.22
		Sales_data sum, data1;
		double price = 0.0;
		if (std::cin >> sum.bookNo >> sum.units_sold >> price) {
			sum.revenue = sum.units_sold * price;
			unsigned totalCnt = sum.units_sold;
			double totalRevenue = sum.revenue;
			while (std::cin >> data1.bookNo >> data1.units_sold >> price) {
				data1.revenue = data1.units_sold * price;
				totalCnt += data1.units_sold;
				totalRevenue += data1.revenue;
				sum.units_sold += data1.units_sold;
				sum.revenue += data1.revenue;
			}
			double avg = totalRevenue / totalCnt;
			std::cout << sum.units_sold << " " << sum.revenue << " " << avg << std::endl;
		}

	} else if (exc == "1.23") {
		// 1.23
		Sales_data book1, book2;
		double price;
		if (std::cin >> book1.bookNo >> book1.units_sold >> price) {
			book1.revenue = book1.units_sold * price;
			unsigned cnt = 1;
			while (std::cin >> book2.bookNo >> book1.units_sold >> price) {
				book2.revenue = book2.units_sold * price;
				if (book1.bookNo == book2.bookNo) {
					++cnt;
				} else {
					std::cout << cnt << " transactions for " << book1.bookNo << std::endl;
					book1.bookNo = book2.bookNo;
					cnt = 1;
				}
			}
			std::cout << cnt << " transactions for " << book1.bookNo << std::endl;
		}
	}
	return 0;
}
