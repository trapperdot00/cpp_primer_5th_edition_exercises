#include <regex>
#include <iostream>

using std::regex;
using std::regex_error;
using std::cout;
using std::endl;

int main() {
	try {
		regex r("[z-a]");
	} catch (regex_error e) {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}
	return 0;
}