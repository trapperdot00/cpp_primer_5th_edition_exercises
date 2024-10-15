#include "chapter17.h"

namespace cplusplus_primer {
	namespace chapter17 {
	namespace _03 {
		typename TextQuery::Result TextQuery::query(const std::string &s) const  {
			static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
			std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator findIt = wm.find(s);
			if (findIt == wm.cend())
				return Result(s, nodata, file);
			else
				return Result(s, findIt->second, file);
		}
	}
	namespace _04 {
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

		std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::istream &operator>>(std::istream &is, Sales_data &item) {
			double price;
			is >> item.bookNo >> item.units_sold >> price;
			if (is)
				item.revenue = item.units_sold * price;
			else
				item = Sales_data();
			return is;
		}

		Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret += rhs;
			return ret;
		}
		Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold -= rhs.units_sold;
			ret.revenue -= rhs.revenue;
			return ret;
		}
		Sales_data operator*(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold *= rhs.units_sold;
			ret.revenue *= rhs.revenue;
			return ret;
		}
		Sales_data operator/(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold /= rhs.units_sold;
			ret.revenue /= rhs.revenue;
			return ret;
		}

		bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
			return lhs.bookNo == rhs.bookNo &&
				   lhs.units_sold == rhs.units_sold &&
				   lhs.revenue == rhs.revenue;
		}

		bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
			return !(lhs == rhs);
		}

		Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		Sales_data &Sales_data::operator=(const std::string &s) {
			bookNo = s;
			units_sold = 0;
			revenue = 0.0;
			return *this;
		}

		bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
			return lhs.isbn() < rhs.isbn();
		}
	}
	namespace _05 {
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

		std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::istream &operator>>(std::istream &is, Sales_data &item) {
			double price;
			is >> item.bookNo >> item.units_sold >> price;
			if (is)
				item.revenue = item.units_sold * price;
			else
				item = Sales_data();
			return is;
		}

		Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret += rhs;
			return ret;
		}
		Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold -= rhs.units_sold;
			ret.revenue -= rhs.revenue;
			return ret;
		}
		Sales_data operator*(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold *= rhs.units_sold;
			ret.revenue *= rhs.revenue;
			return ret;
		}
		Sales_data operator/(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold /= rhs.units_sold;
			ret.revenue /= rhs.revenue;
			return ret;
		}

		bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
			return lhs.bookNo == rhs.bookNo &&
				   lhs.units_sold == rhs.units_sold &&
				   lhs.revenue == rhs.revenue;
		}

		bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
			return !(lhs == rhs);
		}

		Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		Sales_data &Sales_data::operator=(const std::string &s) {
			bookNo = s;
			units_sold = 0;
			revenue = 0.0;
			return *this;
		}

		bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
			return lhs.isbn() < rhs.isbn();
		}
	}
	namespace _06 {
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

		std::ostream &operator<<(std::ostream &os, const Sales_data &item) {
			os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
			return os;
		}

		std::istream &operator>>(std::istream &is, Sales_data &item) {
			double price;
			is >> item.bookNo >> item.units_sold >> price;
			if (is)
				item.revenue = item.units_sold * price;
			else
				item = Sales_data();
			return is;
		}

		Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret += rhs;
			return ret;
		}
		Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold -= rhs.units_sold;
			ret.revenue -= rhs.revenue;
			return ret;
		}
		Sales_data operator*(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold *= rhs.units_sold;
			ret.revenue *= rhs.revenue;
			return ret;
		}
		Sales_data operator/(const Sales_data &lhs, const Sales_data &rhs) {
			Sales_data ret = lhs;
			ret.units_sold /= rhs.units_sold;
			ret.revenue /= rhs.revenue;
			return ret;
		}

		bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
			return lhs.bookNo == rhs.bookNo &&
				   lhs.units_sold == rhs.units_sold &&
				   lhs.revenue == rhs.revenue;
		}

		bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
			return !(lhs == rhs);
		}

		Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
			units_sold += rhs.units_sold;
			revenue += rhs.revenue;
			return *this;
		}

		Sales_data &Sales_data::operator=(const std::string &s) {
			bookNo = s;
			units_sold = 0;
			revenue = 0.0;
			return *this;
		}

		bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
			return lhs.isbn() < rhs.isbn();
		}
	}
	namespace _20 {
		bool valid(const std::smatch &m) {
			// If there is a starting parenthesis in the phone number
			if (m[1].matched) {
				// There must be a closing parenthesis after the area code
				// and there must only be a space delimiter, or none
				return m[3].matched && (m[4].matched == false || m[4].str() == " ");
			} else {
				// If there is no parenthesis before the area code,
				// the delimiters must match
				return !m[3].matched && m[4].str() == m[6].str();
			}
		}
	}
	namespace _21 {
		bool valid(const std::smatch &m) {
			// If there is a starting parenthesis in the phone number
			if (m[1].matched) {
				// There must be a closing parenthesis after the area code
				// and there must only be a space delimiter, or none
				return m[3].matched && (m[4].matched == false || m[4].str() == " ");
			} else {
				// If there is no parenthesis before the area code,
				// the delimiters must match
				return !m[3].matched && m[4].str() == m[6].str();
			}
		}
	}
	namespace _22 {
		bool valid(const std::smatch &m) {
			// If there is a starting parenthesis in the phone number
			if (m[1].matched) {
				// There must be a closing parenthesis after the area code
				// and there must only be a space delimiter, or none
				return m[3].matched && (m[4].matched == false || m[4].str() == " ");
			} else {
				// If there is no parenthesis before the area code,
				// the delimiters must match
				return !m[3].matched && (m[4].str() == m[6].str());
			}
		}
	}
	}
}
