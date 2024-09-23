#include <regex>
#include <fstream>
#include <iostream>
#include <string>

using namespace std::regex_constants;
using std::regex;
using std::regex_replace;
using std::smatch;
using std::string;
using std::ifstream;
using std::getline;
using std::cout;
using std::endl;

int main() {
	ifstream inFile("zipcodes.txt");
	if (inFile.fail()) return -1;
	string pattern = "(\\d{9})";
	regex r(pattern);
	smatch result;
	string formatPattern = "(\\d{5})(\\d{4})";
	regex formatReg(formatPattern);
	string fmt = "$1-$2";
	for (string line; getline(inFile, line); ) {
		cout << regex_replace(line, formatReg, fmt, format_no_copy) << endl;
	}
	return 0;
}
