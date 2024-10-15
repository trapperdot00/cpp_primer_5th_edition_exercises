#ifndef CHAPTER17_H
#define CHAPTER17_H

#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
#include <functional>
#include <regex>

namespace cplusplus_primer {
	namespace chapter17 {
	namespace _03 {
		class TextQuery {
		public:
			typedef std::vector<std::string>::size_type line_no;
			typedef std::tuple<std::string,
					std::shared_ptr<std::set<line_no>>,
					std::shared_ptr<std::vector<std::string>>>
					Result;
			TextQuery(std::ifstream &in) : file(std::make_shared<std::vector<std::string>>()) {
				line_no line_num = 0;
				for (std::string line; std::getline(in, line); file->push_back(line), ++line_num) {
					std::string word;
					std::istringstream stream(line);
					while (stream >> word) {
						std::shared_ptr<std::set<line_no>> &lines = wm[word];
						if (!lines)
							lines.reset(new std::set<line_no>);
						lines->insert(line_num);
					}
				}
			}
			
			Result query(const std::string &) const;
		private:
			std::shared_ptr<std::vector<std::string>> file;
			std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
		};
	}
	namespace _04 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			friend Sales_data operator+(const Sales_data &, const Sales_data &);
			friend Sales_data operator-(const Sales_data &, const Sales_data &);
			friend Sales_data operator*(const Sales_data &, const Sales_data &);
			friend Sales_data operator/(const Sales_data &, const Sales_data &);

			friend bool operator==(const Sales_data &, const Sales_data &);

			friend struct std::hash<Sales_data>;
		public:
			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment
			Sales_data &operator=(const std::string &);		// copy-assignment operator
			
			explicit operator std::string() const { return bookNo; }
			explicit operator double() const { return revenue; }
		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
		Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
		Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
		Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);

		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	}
}
namespace std {
	template <>
	struct hash<cplusplus_primer::chapter17::_04::Sales_data> {
		typedef size_t result_type;
		typedef cplusplus_primer::chapter17::_04::Sales_data argument_type;
		size_t operator()(const cplusplus_primer::chapter17::_04::Sales_data &s) const {
			return hash<string>()(s.bookNo) ^
				   hash<unsigned>()(s.units_sold) ^
				   hash<double>()(s.revenue);
		}
		hash() = default;
		hash &operator=(const hash &) = default;
	};
}
namespace cplusplus_primer {
	namespace chapter17 {
	namespace _05 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			friend Sales_data operator+(const Sales_data &, const Sales_data &);
			friend Sales_data operator-(const Sales_data &, const Sales_data &);
			friend Sales_data operator*(const Sales_data &, const Sales_data &);
			friend Sales_data operator/(const Sales_data &, const Sales_data &);

			friend bool operator==(const Sales_data &, const Sales_data &);

			friend struct std::hash<Sales_data>;
		public:
			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment
			Sales_data &operator=(const std::string &);		// copy-assignment operator
			
			explicit operator std::string() const { return bookNo; }
			explicit operator double() const { return revenue; }
		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
		Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
		Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
		Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);

		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	}
}
namespace std {
	template <>
	struct hash<cplusplus_primer::chapter17::_05::Sales_data> {
		typedef size_t result_type;
		typedef cplusplus_primer::chapter17::_05::Sales_data argument_type;
		size_t operator()(const cplusplus_primer::chapter17::_05::Sales_data &s) const {
			return hash<string>()(s.bookNo) ^
				   hash<unsigned>()(s.units_sold) ^
				   hash<double>()(s.revenue);
		}
		hash() = default;
		hash &operator=(const hash &) = default;
	};
}
namespace cplusplus_primer {
	namespace chapter17 {
	namespace _06 {
		class Sales_data;
			std::istream &read(std::istream&, Sales_data&);

		class Sales_data {
			friend std::istream &read(std::istream&, Sales_data&);
			friend std::ostream &print(std::ostream&, const Sales_data&);
			friend Sales_data add(const Sales_data&, const Sales_data&);
			
			friend std::ostream &operator<<(std::ostream &, const Sales_data &);
			friend std::istream &operator>>(std::istream &, Sales_data &);

			friend Sales_data operator+(const Sales_data &, const Sales_data &);
			friend Sales_data operator-(const Sales_data &, const Sales_data &);
			friend Sales_data operator*(const Sales_data &, const Sales_data &);
			friend Sales_data operator/(const Sales_data &, const Sales_data &);

			friend bool operator==(const Sales_data &, const Sales_data &);

			friend struct std::hash<Sales_data>;
		public:
			Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {
				//std::cout << "mainConstructor" << std::endl;
			}
			Sales_data() : Sales_data("", 0, 0) {
				//std::cout << "empty" << std::endl;	
			}
			Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
				//std::cout << "string" << std::endl;
			}
			Sales_data(std::istream &is) : Sales_data() {
				read(is, *this);
				//std::cout << "istream" << std::endl;
			}

			Sales_data &combine(const Sales_data&);
			std::string isbn() const { return bookNo; }
			
			Sales_data &operator+=(const Sales_data &);		// compound-assignment
			Sales_data &operator=(const std::string &);		// copy-assignment operator
			
			explicit operator std::string() const { return bookNo; }
			explicit operator double() const { return revenue; }
		private:
			double avg_price() const;
			std::string bookNo;
			unsigned units_sold = 0;
			double revenue = 0.0;
		};

		std::istream &operator>>(std::istream &, Sales_data &);			// input operator
		std::ostream &operator<<(std::ostream &, const Sales_data &);	// output operator
		Sales_data operator+(const Sales_data &, const Sales_data &);	// addition operator
		Sales_data operator-(const Sales_data &, const Sales_data &);	// subtraction operator
		Sales_data operator*(const Sales_data &, const Sales_data &);	// multiplication operator
		Sales_data operator/(const Sales_data &, const Sales_data &);	// division operator

		Sales_data add(const Sales_data&, const Sales_data&);
		std::ostream &print(std::ostream&, const Sales_data&);

		// inline and constexpr functions should be defined in the class headers
		inline
		double Sales_data::avg_price() const {
			return units_sold ? revenue / units_sold : 0;
		}
	}
	}
}
namespace std {
	template <>
	struct hash<cplusplus_primer::chapter17::_06::Sales_data> {
		typedef size_t result_type;
		typedef cplusplus_primer::chapter17::_06::Sales_data argument_type;
		size_t operator()(const cplusplus_primer::chapter17::_06::Sales_data &s) const {
			return hash<string>()(s.bookNo) ^
				   hash<unsigned>()(s.units_sold) ^
				   hash<double>()(s.revenue);
		}
	hash() = default;
	hash &operator=(const hash &) = default;
	};
}
namespace cplusplus_primer {
	namespace chapter17 {
	namespace _20 {
		bool valid(const std::smatch &);
	}
	namespace _21 {
		bool valid(const std::smatch &);

		struct PersonInfo {
			std::string name;
			std::vector<std::string> phones;
		};
	}
	namespace _22 {
		bool valid(const std::smatch &);

		struct PersonInfo {
			std::string name;
			std::vector<std::string> phones;
		};
	}
	}
}

#endif
