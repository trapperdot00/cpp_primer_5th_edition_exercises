#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <utility>
#include <cstddef>
#include <stdexcept>
#include <sstream>

using std::map;
using std::string;
using std::function;
using std::cin;
using std::cout;
using std::endl;
using std::modulus;
using std::istringstream;
using std::getline;
using std::size_t;
using std::runtime_error;

struct subtraction {
	int operator()(int i, int j) { return i - j; }
};

string multiplication(const string &s1, const string &s2) { return ""; }	// dummy func for overloading
int multiplication(int i, int j) { return i * j; }

string division(const string &s1, const string &s2) { return ""; }	// dummy func for overloading
int division(int i, int j) { return i / j; }

int main() {
	int (*fp)(int, int) = division;		// disambiguating overload with the type of function pointer
	map<string, function<int (int, int)>> binops = {
		{"+", [](int i, int j) { return i + j; }},
		{"-", subtraction()},						// user-defined function object
		{"*", [](int i, int j) { return multiplication(i, j); }},	// disambiguating overload with lambda
		{"/", fp},
		{"%", modulus<int>()}
	};

	string line;
	while (getline(cin, line)) {
		istringstream stream(line);
		function<int (int, int)> func;
		
		int num1, num2;
		string query;
		if (!(stream >> num1 >> query >> num2))
			throw runtime_error("invalid inputs");

		map<string, function<int (int, int)>>::iterator it = binops.find(query);
		if (it == binops.end())
			throw runtime_error("no operator matches");
		func = it->second;

		cout << func(num1, num2) << endl;
	}
	return 0;
}
