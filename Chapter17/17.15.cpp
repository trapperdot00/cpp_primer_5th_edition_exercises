#include <regex>
#include <iostream>
#include <string>

using std::regex;
using std::regex_search;
using std::smatch;
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
	regex badWordR("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);
	smatch result;
	string word;
	cout << "Enter words: ";
	while (cin >> word) {
		if (regex_search(word, result, badWordR)) {
			cout << word << " violates the \"i before e except after c\" rule: "
				 << result.str() << endl;
		} else
			cout << "no violations" << endl;
	}
	return 0;
}
