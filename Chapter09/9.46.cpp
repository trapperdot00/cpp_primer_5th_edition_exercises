#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

string &prefixSuffix(string &s, const string &prefix, const string &suffix) {
	s.insert(0, prefix + " ");
	s.insert(s.size(), " " + suffix);
	return s;
}

int main() {
	string name;
	if (getline(cin, name)) {
		string prefix, suffix;
		if (cin >> prefix >> suffix)
			cout << prefixSuffix(name, prefix, suffix) << endl;
	}
	return 0;
}
