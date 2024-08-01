#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

int main() {
	string s1;
	if (!getline(cin, s1)) { return -1; }
	string s2;
	if (!getline(cin, s2)) { return -1; }
	
	if (s1 == s2) {
		cout << "The two strings are equal." << endl;
	} else if (s1 > s2) {
		cout << "The first string is larger than the second one." << endl;
	} else {
		cout << "The second string is larger than the first one." << endl;
	}
	return 0;
}
