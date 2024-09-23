#include "valid.h"

#include <regex>
#include <fstream>
#include <string>
#include <iostream>

using std::regex;
using std::sregex_iterator;
using std::ifstream;
using std::getline;
using std::string;
using std::cout;
using std::endl;

int main() {
	const string filename = "phone_numbers.txt";
	ifstream infile(filename);
	if (!infile.is_open()) return -1;
	string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(pattern);
	string line;
	while (getline(infile, line)) {
		for (sregex_iterator it(line.cbegin(), line.cend(), r), end;
				it != end; ++it) {
			if (valid(*it))
				cout << "valid:\t\t" << it->str() << endl;
			else
				cout << "invalid:\t" << it->str() << endl;
		}
	}
	return 0;
}
