#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
	vector<string> text;
	for (unsigned cnt = 0; cnt != 15; ++cnt) {
		text.push_back("Asdfghjk asdfghjk, asdfghjk asdfghjk. Asdfghjk asdfghjk.");
		text.push_back("");
	}

	for (vector<string>::iterator it = text.begin(); it != text.end() && !it->empty(); ++it) {
		for (string::iterator ci = it->begin(); ci != it->end(); ++ci) {
			*ci = toupper(*ci);
		}
	}
	for (vector<string>::const_iterator it = text.cbegin(); it != text.cend(); ++it) {
		cout << *it << endl;
	}
	return 0;
}
