#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	string large;
	if (!(cin >> large)) { return -1; }
	large += ' ';
	string s;
	while (cin >> s) {
		large += s + ' ';
	}
	cout << large << endl;
	return 0;
}
