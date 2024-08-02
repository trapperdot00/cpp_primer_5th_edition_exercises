#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void findEachNum(const string &s) {
	const string numbers("0123456789");
	string::size_type index = 0;
	while ((index = s.find_first_of(numbers, index)) != string::npos) {
		cout << "Found numeric value: " << s[index] << " at: " << index << endl;
		++index;
	}
}

void findEachAlp(const string &s) {
	const string numbers("0123456789");
	string::size_type index = 0;
	while ((index = s.find_first_not_of(numbers, index)) != string::npos) {
		cout << "Found alphabetic value: " << s[index] << " at: " << index << endl;
		++index;
	}
}

int main() {
	const string s("ab2c3d7R4E6");
	findEachNum(s);
	findEachAlp(s);
	return 0;
}
