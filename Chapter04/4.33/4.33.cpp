#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	int someValue;
	int x = 10, y = 20;
	cout << "x=" << x << " y=" << y << endl;
	cout << "Some value: ";
	cin >> someValue;
	cout << (someValue ? ++x, ++y : --x, --y) << endl;
	cout << "x=" << x << " y=" << y << endl;
	return 0;
}
