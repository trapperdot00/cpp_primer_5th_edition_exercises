#include <regex>
#include <string>
#include <fstream>
#include <iostream>

using std::regex;
using std::smatch;
using std::regex_match;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

int main() {
	ifstream infile("zipcodes.txt");
	if (infile.fail()) return -1;

	regex r("((\\d{5})(-\\d{4})?)|(\\d{9})");
	smatch results;
	for (string entry; infile >> entry; ) {
		if (regex_match(entry, results, r))
			cout << "found zipcode:\t\t" << results.str() << endl;
	}
	return 0;
}
