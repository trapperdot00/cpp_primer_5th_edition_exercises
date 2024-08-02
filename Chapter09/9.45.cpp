#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::cin;

string &prefixSuffix(string &s, const string &prefix, const string &suffix) {
	s.insert(s.begin(), 1, ' ');
	s.insert(s.begin(), prefix.begin(), prefix.end());
	s.append(" ");
	s.append(suffix.cbegin(), suffix.cend());
	return s;
}

int main() {
	string s;
	cout << "Enter name: ";
	if (getline(cin, s)) {
		string prefix, suffix;
		cout << "Enter prefix and suffix: ";
		if (cin >> prefix >> suffix)
			cout << prefixSuffix(s, prefix, suffix) << endl;
	}
	return 0;
}
