#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string large;
	if (!(cin >> large)) { return -1; }
	string s;
	while (cin >> s) {
		large += s;
	}
	cout << large << endl;

	return 0;
}	
