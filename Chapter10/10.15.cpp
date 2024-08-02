#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	cout << "Enter two numbers to sum with a lambda expression: ";
	int i, i2;
	cin >> i >> i2;
	auto l = [i](int j) { return i + j; };
	cout << l(i2) << endl;
	return 0;
}
