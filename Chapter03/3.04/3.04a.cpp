#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
	string s1;
	if (!(cin >> s1)) { return -1; }
	string s2;
	if (!(cin >> s2)) { return -1; }

	if (s1 == s2) {
		cout << "The two strings are equal" << endl;
	} else if (s1 > s2) {
		cout << "The first string is larger" << endl;
	} else {
		cout << "The second string is larger" << endl;
	}
	return 0;
}
