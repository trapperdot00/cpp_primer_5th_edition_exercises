#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;

int main() {
	int num1, num2;
	cin >> num1 >> num2;
	if (num2 == 0)
		throw runtime_error("Error: dividing by zero.");
	cout << num1 / num2 << endl;
	return 0;
}
