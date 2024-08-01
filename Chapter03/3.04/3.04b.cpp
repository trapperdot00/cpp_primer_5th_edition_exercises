#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

int main() {
	string s1;
	if (!(cin >> s1)) { return -1; }
	string s2;
	if (!(cin >> s2)) { return -1; }
	
	if (s1.size() == s2.size()) {
		cout << "The strings are of equal size" << endl;
	} else if (s1.size() > s2.size()) {
		cout << "The first string's size is larger" << endl;
	} else {
		cout << "The second string's size is larger" << endl;
	}

	return 0;
}
