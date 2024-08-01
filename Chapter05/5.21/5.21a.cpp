#include <cctype>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
	string curr, prev;
	while (cin >> curr && !curr.empty()) {
		if (curr == prev && isupper(curr[0])) {
			cout << "Duplicated word that starts with an uppercase letter!!!" << endl;
		}
		prev = curr;
	}
	return 0;
}
