#include <string>
#include <iostream>
#include <cctype>
using std::string;
using std::cout;
using std::endl;

int main() {
	const string s("ab2c3d7R4E6");
	string numerics("0123456789"), alphabetic("abcdefghijklmnopqrstuvwxyz");
	string::size_type index = 0, oldSize = alphabetic.size();
	while (index != oldSize) {
		if (islower(alphabetic[index])) {
			alphabetic.push_back(toupper(alphabetic[index]));
		}
		++index;
	}
	cout << alphabetic << endl;
	index = 0;
	while ((index = s.find_first_of(numerics, index)) != string::npos) {
		cout << "Numeric found: " << s[index] << endl;
		++index;
	}
	index = 0;
	cout << endl;
	while ((index = s.find_first_not_of(alphabetic, index)) != string::npos) {
		cout << "Numeric found: " << s[index] << endl;
		++index;
	}

	index = 0;
	cout << endl;
	while ((index = s.find_first_of(alphabetic, index)) != string::npos) {
		cout << "Alphabetic found: " << s[index] << endl;
		++index;
	}
	index = 0;
	cout << endl;
	while ((index = s.find_first_not_of(numerics, index)) != string::npos) {
		cout << "Alphabetic found: " << s[index] << endl;
		++index;
	}

	return 0;
}
