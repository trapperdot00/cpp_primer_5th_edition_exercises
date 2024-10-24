#include <string>
#include <vector>
#include <iostream>

struct Base1 {
	void print(int i) const {
		std::cout << i << std::endl;
	}
protected:
	int		ival;
	double	dval;
	char	cval;
private:
	int		*id;
};

struct Base2 {
	void print(double d) const {
		std::cout << d << std::endl;
	}
protected:
	double	fval;
private:
	double	dval;
};

struct Derived : public Base1 {
	void print(std::string s) const {
		std::cout << s << std::endl;
	}
protected:
	std::string	sval;
	double		dval;
};

struct MI : public Derived, public Base2 {
	void print(std::vector<double> vec) {
		for (const double &d : vec) {
			std::cout << d << std::endl;
		}
	}
	void print(int i) const {
//		Derived::Base1::print(i);		ugly!
		Base1::print(i);
	}
	void print(double d) const {
		Base2::print(d);
	}
	void print(std::string s) const {
		Derived::print(s);
	}
protected:
	int					*ival;
	std::vector<double>	 dvec;
};

int main() {
	MI mi;
	mi.print(42);
	mi.print({1,2,3,4});
	mi.print(3.14);
	mi.print("hello");
	return 0;
}
