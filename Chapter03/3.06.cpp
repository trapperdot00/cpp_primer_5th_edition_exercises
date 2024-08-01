#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::getline;

int main() {
	string s;
	if (!getline(cin,  s)) { return -1; }
	for (auto &c : s) {
		c = 'X';
	}
	cout << s << endl;
	return 0;
}

