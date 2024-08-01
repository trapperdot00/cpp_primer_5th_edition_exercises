#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int num;
	while (cin >> num && num != 42) {
		cout << num << endl;
	}
	return 0;
}
