#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::getline;
using std::cin;

int main() {
	string s;
	if (!getline(cin, s)) { return -1; }
	for (char c : s) {
		c = 'X';
	}
	cout << s << endl;
	return 0;
}
