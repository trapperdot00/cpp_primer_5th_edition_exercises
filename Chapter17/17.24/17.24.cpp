#include <regex>
#include <string>
#include <fstream>
#include <iostream>

using std::regex;
using std::regex_replace;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

int main() {
	ifstream infile("phone_numbers.txt");
	if (infile.fail()) return -1;
	string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(pattern);
	string fmt = "$2.$5.$7";
	for (string line; getline(infile, line); ) {
		cout << regex_replace(line, r, fmt) << endl;
	}
	return 0;
}
