#ifndef CHAPTER07_H
#define CHAPTER07_H

#include <string>
#include <iostream>
#include <cstddef>
#include <vector>

namespace cplusplus_primer {
namespace chapter07 {
	class Account {
	public:
		void calculate() { amount += amount * interestRate; }
		static double rate() { return interestRate; }
		static void rate(double);
	private:
		std::string owner;
		double amount;
		static double interestRate;
		static double initRate();
		static constexpr int period = 30;
		double daily_tbl[period];
	};

	class Debug {
	public:
		constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
		constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

		constexpr bool any() const { return hw || io || other; }

		void set_hw(bool b) { hw = b; }
		void set_io(bool b) { io = b; }
		void set_other(bool b) { other = b; }
	private:
		bool hw;
		bool io;
		bool other;
	};

	class Employee {
	public:
		explicit Employee(const std::string &n) : Employee(n, 18) {}
		Employee(const std::string &n, unsigned a) : Employee(n, a, "") {}
		Employee(const std::string &n, unsigned a, const std::string &r) : name(n), age(a), rank(r) {}
	private:
		std::string name;
		unsigned age;
		std::string rank;
	};

	class Sales_data;
	std::istream &read(std::istream&, Sales_data&);

	class Sales_data {
		friend std::istream &read(std::istream &, Sales_data &);
		friend std::ostream &print(std::ostream &, const Sales_data &);
	public:
		Sales_data() : Sales_data("", 0, 0)
			{ std::cout << "Sales_data()" << std::endl; }
		Sales_data(const std::string &s) : Sales_data(s, 0, 0)
			{ std::cout << "Sales_data(const std::string &)" << std::endl; }
		Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n)
			{ std::cout << "Sales_data(const std::string &, unsigned, double)" << std::endl; }
		Sales_data(std::istream &is)
			{ std::cout << "Sales_data(std::istream &)" << std::endl; read(is, *this); }

		Sales_data &combine(const Sales_data&);
		std::string isbn() const { return bookNo; }
		inline double avg_price() const;

	private:
		std::string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
	};

	Sales_data add(const Sales_data&, const Sales_data&);
	std::ostream &print(std::ostream&, const Sales_data&);

	inline double Sales_data::avg_price() const {
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}

	class Screen;

	class Window_mgr {
	public:
		Window_mgr();
		using ScreenIndex = std::vector<Screen>::size_type;
		void clear(ScreenIndex);
	private:
		std::vector<Screen> screens;
	};

	class Screen {
		friend void Window_mgr::clear(ScreenIndex);
	public:
		typedef std::string::size_type pos;
		Screen() = default;
		Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
		Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

		char get() const { return contents[cursor]; }
		inline char get(pos ht, pos wd) const;
		Screen &move(pos r, pos c);
		void some_member() const;
		
		Screen &set(char);
		Screen &set(pos, pos, char);
		Screen &display(std::ostream &os)
			{ do_display(os); return *this; }
		const Screen &display(std::ostream &os) const 
			{ do_display(os); return *this; }

	private:
		void do_display(std::ostream &os) const { os << contents; }

		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;

		mutable std::size_t access_ctr = 0;
	};

	inline Screen &Screen::move(pos r, pos c) {
		pos row = r * width;
		cursor = row + c;
		return *this;
	}

	char Screen::get(pos r, pos c) const {
		pos row = r * width;
		return contents[row + c];
	}

	inline Screen &Screen::set(char c) {
		contents[cursor] = c;
		return *this;
	}

	inline Screen &Screen::set(pos r, pos col, char ch) {
		contents[r * width + col] = ch;
		return *this;
	}

	class Person {
		friend std::istream &read(std::istream &, Person &);
		friend std::ostream &print(std::ostream &, const Person &);
	public:
		Person(const std::string &n = "") : name(n) {}
		Person(const std::string &n, const std::string &a) : name(n), address(a) {}

		std::string getName() const { return name; }
		std::string getAddress() const { return address; }
	private:
		std::string name;
		std::string address;
	};

	std::istream &read(std::istream &, Person &);
	std::ostream &print(std::ostream &, const Person &);
}
}

#endif
