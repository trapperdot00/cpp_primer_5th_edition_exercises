#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int num1, num2;
	if (!(cin >> num1 >> num2))
		return -1;
	if (num1 <= num2) {
		while (num1 <= num2) {
			cout << num1 << endl;
			++num1;
		}
	} else {
		while (num1 >=  num2) {
			cout << num1 << endl;
			--num1;
		}
	}
	return 0;
}
