#include <iostream>

using std::cout;
using std::endl;

int main() {
	int num = 50, sum = 0;
	while (num <= 100) {
		sum += num;
		++num;
	}
	cout << sum << endl;
	return 0;
}
