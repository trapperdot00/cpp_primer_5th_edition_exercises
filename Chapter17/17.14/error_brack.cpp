#include <regex>
#include <iostream>
#include <string>

using std::regex;
using std::regex_error;
using std::cout;
using std::endl;
using std::string;

int main() {
	string text = "[[:alnum:]+\\.(cpp|cxx|cc)$";
	try {
		regex r(text, regex::icase);
	} catch (regex_error e)  {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}
	return 0;
}
