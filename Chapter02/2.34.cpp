#include <iostream>

using namespace std;

int main() {
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	const auto f = ci;
	auto &g = ci;
	//auto &h = 42;
	const auto &j = 42;
	auto k = ci, &l = i;
	auto &m = ci, *p = &ci;
	
	cout << "a: " << a << "\n" << "b: " << b << "\n" << "c: " << c << "\n" << "*d: " << *d << "\n" << "*e: " << *e << "\n" << "g:" << g << "\n\n";

	a = 42;
	b = 42;
	c = 42;
	*d = 42;
	e = d;
	// g = 42;

	cout << "a: " << a << "\n" << "b: " << b << "\n" << "c: " << c << "\n" << "*d: " << *d << "\n" << "*e: " << *e << "\n" << "g:" << g << endl;

	return 0;
}
