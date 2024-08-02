#include <map>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::list;
using std::istringstream;

std::ostream &print(std::ostream &os, const map<string, list<unsigned>> &m) {
	for (const auto &e : m) {
		os << e.first << ": ";
		for (unsigned u : e.second) {
			os << u << ' ';
		}
		os << endl;
	}
	return os;
}

int main(int argc, char *argv[]) {
	string filename = argv[1];
	cout << filename << endl;
	ifstream infile(filename);
	map<string, list<unsigned>> word_line;
	string line;
	unsigned lineNum = 1;
	while (getline(infile, line)) {
		istringstream stream(line);
		string word;
		while (stream >> word) {
			list<unsigned> &lineCountL = word_line[word];
			lineCountL.push_back(lineNum);
		}
		++lineNum;
	}
	print(cout, word_line);
	return 0;
}
