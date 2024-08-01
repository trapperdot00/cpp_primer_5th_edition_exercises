#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

using std::runtime_error;
using std::cin;
using std::string;
using std::cout;
using std::endl;

bool hasCapital(const string &s) {
	for (const char &c : s) {
		if (isupper(c))
			return true;
	}
	return false;
}

void toLowercase(string &s) {
	for (char &c : s){
		c = tolower(c);
	}
}

int main() {
	bool torepeat;
	do {
		try {
			torepeat = false;
			string word;
			if (!(cin >> word))
				throw runtime_error("Invalid input!");
			if (hasCapital(word)) {
				cout << "String contains at least one capital letter." << endl;
				toLowercase(word);
				cout << "Lowercase string: " << word << endl;
			} else {
				cout << "String doesn't have any capital letters." << endl;
			}

		} catch (runtime_error e) {
			cout << e.what() << "\nTry again? (y/n): ";
			char choice;
			if (cin >> choice && choice == 'y')
				torepeat = true;
		}
	} while (torepeat);
	return 0;
}
