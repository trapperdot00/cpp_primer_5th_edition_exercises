#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::getline;
using std::string;
using std::vector;

int main() {
	vector<string> svec;
	string s;
	while (getline(cin, s)) {
		svec.push_back(s);
	}
	return 0;
}
