#include <regex>
#include <string>
#include <fstream>
#include <iostream>

using std::regex;
using std::regex_replace;
using namespace std::regex_constants;
using std::string;
using std::ifstream;
using std::getline;
using std::cout;
using std::endl;

int main() {
	ifstream inFile("people.txt");
	if (inFile.fail()) return -1;
	regex r("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");
	string fmt = "$2.$5.$7 ";
	for (string line; getline(inFile, line); ) {
		cout << line.substr(0, line.find('\t')) << ":\t\t"
			 << regex_replace(line, r, fmt, format_first_only | format_no_copy) << endl;
	}
	return 0;
}
