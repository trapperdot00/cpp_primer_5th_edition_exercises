#include "print.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Base {
public:
	Base(const string &s = "") : name(s) {}
	virtual ~Base() = default;

	virtual std::string rep() const {
		return name;
	}
protected:
	string name;
};

class Derived final : public Base {
public:
	Derived() : Base(), value(0) {}
	Derived(const string &s, int i) : Base(s), value(i) {}

	std::string rep() const override {
		return name + std::to_string(value);
	}
private:
	int value;
};

std::ostream &operator<<(std::ostream &os, const Base &b) {
	return os << b.rep();
}

int main() {
	int i = 12;
	double d = 1.2;
	string s = "word";
	Base obj1("Base");
	Derived obj2("Derived", 12);

	print(cout, i) << endl;
	print(cout, i, d, s) << endl;
	print(cout, i, d, s, obj1, obj2) << endl;
	return 0;
}
