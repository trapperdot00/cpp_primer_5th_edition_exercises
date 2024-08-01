#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

int main() {
	string s;
	if (!getline(cin, s)) { return -1; }
	string fs;
	for (auto &c : s) {
		if (!ispunct(c)) {
			cout << c;
		}
	}
	cout << endl;
}

