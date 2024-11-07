#include <typeinfo>
#include <iostream>
#include <string>
#include <map>

#include "Sales_data.h"

class Base {};
class Derived : public Base {};

using std::cout;
using std::endl;
using std::map;

std::string translate(const std::string &name) {
	static const map<std::string, std::string> trans_list {
		{"i", "int"},
		{"A10_i", "array of ints of size 10"},
		{"10Sales_data", "Sales_data"},
		{"NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE", "std::string"},
		{"P4Base", "Base *"},
		{"4Base", "Base"},
		{"c", "char"},
		{"j", "unsigned"},
		{"s", "short"},
		{"t", "unsigned short"},
		{"h", "unsigned char"},
		{"a", "signed char"},
		{"l", "long"},
		{"x", "long long"},
		{"m", "unsigned long"},
		{"y", "unsigned long long"},
		{"f", "float"},
		{"d", "double"},
		{"b", "bool"}
	};
	if (trans_list.count(name))
		return trans_list.at(name);
	return name;
}

int main() {
	int arr[10];
	Derived d;
	Base *p = &d;
	cout << translate(typeid(42).name()) << ",\n"
		 << translate(typeid(arr).name()) << ",\n"
		 << translate(typeid(Sales_data).name()) << ",\n"
		 << translate(typeid(std::string).name()) << ",\n"
		 << translate(typeid(p).name()) << ",\n"
		 << translate(typeid(*p).name()) << ",\n"
		 << translate(typeid(char).name()) << ",\n"
		 << translate(typeid(unsigned).name()) << ",\n"
		 << translate(typeid(short).name()) << ",\n"
		 << translate(typeid(unsigned short).name()) << ",\n"
		 << translate(typeid(unsigned char).name()) << ",\n"
		 << translate(typeid(signed char).name()) << ",\n"
		 << translate(typeid(long).name()) << ",\n"
		 << translate(typeid(long long).name()) << ",\n"
		 << translate(typeid(unsigned long).name()) << ",\n"
		 << translate(typeid(unsigned long long).name()) << ",\n"
		 << translate(typeid(float).name()) << ",\n"
		 << translate(typeid(double).name()) << ",\n"
		 << translate(typeid(bool).name()) << endl;

	return 0;
}
