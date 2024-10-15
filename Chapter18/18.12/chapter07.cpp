#include "chapter07.h"

namespace cplusplus_primer {
namespace chapter07 {
	double Account::initRate() {
		return 0.25;
	}

	void Account::rate(double newRate) {
		interestRate = newRate;
	}

	double Account::interestRate = initRate();

	constexpr int Account::period;

	Sales_data &Sales_data::combine(const Sales_data &rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}

	// NONMEMBER FUNCTIONS

	Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
		Sales_data sum = lhs;
		sum.combine(rhs);
		return sum;
	}

	std::istream &read(std::istream &is, Sales_data &item) {
		double price = 0.0;
		is >> item.bookNo >> item.units_sold >> price;
		item.revenue = item.units_sold * price;
		return is;
	}

	std::ostream &print(std::ostream &os, const Sales_data &item) {
		os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
		return os;
	}

	Window_mgr::Window_mgr() : screens{Screen(24, 80, ' ')} {}

	void Window_mgr::clear(ScreenIndex i) {
		Screen &s = screens[i];
		s.contents = std::string(s.height * s.width, ' ');
	}

	void Screen::some_member() const {
		++access_ctr;
	}

	std::istream &read(std::istream &is, Person &p) {
		is >> p.name >> p.address;
		return is;
	}

	std::ostream &print(std::ostream &os, const Person &p) {
		os << p.getName() << " " << p.getAddress();
		return os;
	}
}
}
