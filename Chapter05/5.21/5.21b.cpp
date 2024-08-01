#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
	string curr, prev;
	bool repeated = false;
	while (cin >> curr) {
		if (curr == prev && isupper(curr[0])) {
			repeated = true;
			break;
		}
		prev = curr;
	}

	if (repeated) {
		cout << curr << " is a duplicated word that starts with an uppercase." << endl;
	} else {
		cout << "No word was repeated." << endl;
	}
	
	return 0;
}
