#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
	unsigned grade;
	cout << "grade: ";
	if (!(cin >> grade)) { return -1; }
	string finalgrade;
	if (grade > 90) {
		finalgrade = "high pass";
	} else if (grade > 75) {
		finalgrade = "pass";
	} else if (grade >= 60) {
		finalgrade = "low pass";
	} else {
		finalgrade = "fail";
	}
	cout << finalgrade << endl;
	return 0;
}
