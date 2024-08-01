#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	unsigned grade;
	cout << "grade: ";
	if (!(cin >> grade)) { return -1; }
	string finalgrade = (grade > 90) ? "high pass"
									 : (grade < 60) ? "fail"
									 : (grade < 76) ? "low pass" : "pass";
	cout << finalgrade << endl;
	return 0;
}
