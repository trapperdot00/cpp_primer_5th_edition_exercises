#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;

int main() {
	int num1, num2 = 0;
	while (num2 == 0) {
		try {
			cin >> num1 >> num2;
			if (num2 == 0)
				throw runtime_error("Error: dividing by zero.");
			cout << num1 / num2 << endl;
		} catch (runtime_error err) {
			cout << err.what() << "\nTry again? Enter y or n" << endl;
			char c;
			if (!(cin >> c) || c == 'n')
				break;
		}
	}
	return 0;
}
