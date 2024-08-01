#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

int main() {
	string s;
	if (!getline(cin, s)) { return -1; }
	string::size_type n = 0;
	while (n < s.size()) {
		s[n] = 'X';
		++n;
	}
	cout << s << endl;
	return 0;
}
