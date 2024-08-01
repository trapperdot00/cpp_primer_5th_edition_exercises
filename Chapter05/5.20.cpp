#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
	string curr, prev;
	bool repeated = false;
	while (cin >> curr) {
		if (curr == prev) {
			repeated = true;
			break;
		}
		prev = curr;
	}

	if (repeated) {
		cout << curr << " repeats." << endl;
	} else {
		cout << "No word was repeated." << endl;
	}
	
	return 0;
}
