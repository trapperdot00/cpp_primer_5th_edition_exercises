#include <map>
#include <iostream>
#include <string>

using std::multimap;
using std::string;
using std::cout;
using std::endl;
using std::cin;

std::ostream &print(std::ostream &os, const multimap<string, string> &mm) {
	string prevAuth;
	bool first = true;
	for (multimap<string, string>::const_iterator it = mm.cbegin(); it != mm.cend(); ++it) {
		if (it->first != prevAuth) {
			if (!first) {
				os << '\n';
			} else {
				first = false;
			}
			os << it->first << ": " << it->second;
		} else {
			os << ' ' << it->second;
		}
		prevAuth = it->first;
	}
	return os;
}

void prompt(multimap<string, string> &mm) {
	string removeKey;
	cout << "\nEnter key to remove: ";
	cin >> removeKey;
	multimap<string, string>::iterator found = mm.find(removeKey);
	if (found != mm.end()) {
		mm.erase(found);
	}
}

int main() {
	multimap<string, string> authors = {{"A", "bookAC"},{"B", "bookBB"},{"C", "bookC"},{"A", "bookAB"},{"D", "bookD"},{"B", "bookBA"},{"E", "bookE"},{"A", "bookAA"},{"F", "bookF"},{"G", "bookGB"},{"G", "bookGA"},{"G", "bookGC"}};
	while (authors.cbegin() != authors.cend() && cin) {
		print(cout, authors);
		prompt(authors);
	}
	return 0;
}
