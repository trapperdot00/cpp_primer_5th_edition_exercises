#include <string>
#include <iostream>
#include <cstddef>

using std::cin;
using std::cout;
using std::endl;

int main() {
	std::size_t sz;
	cin >> sz;
	char *p = new char[sz];
	cin >> p;
	cout << p << endl;
	delete[] p;
	return 0;
}
