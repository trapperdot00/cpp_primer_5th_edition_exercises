#include <string>
#include <iostream>
#include <cstddef>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

string &replaceAbbr(string &s, const string &oldVal, const string &newVal) {
	const string::size_type oldSize = oldVal.size(),
		  					newSize = newVal.size();
	string::size_type index = 0;
	while (index != s.size()) {
		if (s.substr(index, oldSize) == oldVal) {
			s.replace(index, oldSize, newVal);
			index += newSize;
		} else {
			++index;
		}
	}
	return s;
}

void doTheStuff(string &s) {
	vector<string> oldS = {"tho", "thru"}, newS = {"though", "through"};
	for (vector<string>::size_type index = 0; index != 2; ++index)
		cout << replaceAbbr(s, oldS[index], newS[index]) << endl;
}

int main() {
	string s;
	while (getline(cin, s))
		doTheStuff(s);
	return 0;
}
