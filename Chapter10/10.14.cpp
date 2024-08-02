#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
	cout << "Enter two numbers to sum with a lambda expression: ";
	int a, b;
	cin >> a >> b;
	
	auto l = [](int i, int j) -> int { return i + j; };	// we have to supply the variables to add with the parameter list
	cout << l(a, b) << endl;

	auto l2 = [a, b]() -> int { return a + b; };	// with the capture list, we can supply local variables into the lambda, no need for parameter list
	// alternate: [a, b] {return a + b;}	// can omit either or both the return type and parameter list
	cout << l2() << endl;
	return 0;
}
