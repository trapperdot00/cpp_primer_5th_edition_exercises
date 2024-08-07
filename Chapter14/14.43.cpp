#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;
using std::modulus;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<int> divisors{2, 3, 4, 5, 6, 7, 8, 9, 10};
	int val = 0;
	cin >> val;
	modulus<int> check;
	bool divisible = false;
	for (int i : divisors) {
		if (!check(val, i)) {
			if (!divisible) {
				cout << "divisible by ";
				divisible = true;
			}
			cout << i << ' ';;
		}
	}
	if (!divisible)
		cout << "not divisible" << endl;
	else
		cout << endl;
	return 0;
}
