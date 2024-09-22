#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <set>

using std::regex;
using std::regex_search;
using std::sregex_iterator;
using std::smatch;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::getline;
using std::set;

string readFile(std::istream &is) {
	string content;
	bool first = true;
	for (string line; getline(is, line); ) {
		if (!first) {
			content += ' ';
		}
		content += line;
		first = false;
	}
	return content;
}

int main() {
	// Regex Pattern
	string pattern = "[^c]ei";
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);

	// Legal words
	set<string> legalWords = {"albeit", "neighbor", "being", "reign", "heir"};

	// Read file into string
	ifstream infile("text.txt");
	string file = readFile(infile);
	
	// Report errors
	for (sregex_iterator it(file.cbegin(), file.cend(), r), end;
			it != end; ++it) {
		if (legalWords.find(it->str()) != legalWords.cend()) continue;
		auto pos = it->prefix().length();
		pos = pos > 40 ? pos - 40 : 0;
		cout << it->prefix().str().substr(pos)
			 << "\n\t\t>>> " << it->str() << " <<<\n"
			 << it->suffix().str().substr(0, 40) << endl;
	}

	return 0;
}
