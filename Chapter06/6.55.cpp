#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

int add(int num1, int num2) {
	return num1 + num2;
}

int subtract(int num1, int num2) {
	return num1 - num2;
}

int multiply(int num1, int num2) {
	return num1 * num2;
}

int divide(int num1, int num2) {
	return num1 / num2;
}

int main() {
	int num1, num2;
	if (!(cin >> num1 >> num2)) return -1;
	vector<int (*) (int, int)> funcs = {add, subtract, multiply, divide};
	for (int (*func) (int, int) : funcs) {
		cout << func(num1, num2) << endl;
	}
	return 0;
}
