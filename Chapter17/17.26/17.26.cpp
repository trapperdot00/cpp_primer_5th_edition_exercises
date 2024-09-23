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
using std::smatch;
using std::regex_search;

int main() {
	ifstream inFile("people.txt");
	if (inFile.fail()) return -1;
	regex r("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");
	string fmt = "$2.$5.$7 ";
	smatch result;
	for (string line; getline(inFile, line); ) {
		if (regex_search(line, result, r)) {
			if (!result.suffix().str().empty())
				cout << line.substr(0, line.find('\t')) << ":\t\t"
					 << regex_replace(result.suffix().str(), r, fmt, format_no_copy) << endl;
			else
				cout << line.substr(0, line.find('\t')) << ":\t\t"
					 << regex_replace(result.str(), r, fmt, format_no_copy) << endl;
		}
	}
	return 0;
}
