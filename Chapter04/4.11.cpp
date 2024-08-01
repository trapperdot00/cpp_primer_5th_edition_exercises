#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
	int a, b, c, d;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	cout << "d: ";
	cin >> d;

	if (a > b && b > c && c > d) {
		cout << "a is greater than b, b is greater than c, and c is greater than d." << endl;
	} else {
		cout << "fail" << endl;
	}

	return 0;
}
