#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <cstddef>

using std::istringstream;
using std::string;
using std::map;
using std::set;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::size_t;

vector<string> readFile(ifstream &input) {
	vector<string> content;
	for (string line; getline(input, line); content.push_back(line)) ;
	return content;
}

map<string, set<size_t>> mapper(const vector<string> &vec) {
	map<string, set<size_t>> ret;
	size_t lineNum = 1;
	for (const string &line : vec) {
		istringstream stream(line);
		string word;
		while (stream >> word) {
			ret[word].insert(lineNum);
		}
		++lineNum;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	if (argc < 2) return -1;
	ifstream infile(argv[1]);
	vector<string> text = readFile(infile);
	map<string, set<size_t>> word_line = mapper(text);
	do {
		string s;
		cout << "enter word to look for, or q to quit: ";
		if (!(cin >> s) || s == "q") break;
		if (word_line.find(s) != word_line.end()) {	
			size_t occurs = word_line.find(s)->second.size();
			cout << s << " occurs " << occurs << " times" << endl;
			for (set<size_t>::const_iterator lineNumIt = word_line.find(s)->second.cbegin(); lineNumIt != word_line.find(s)->second.cend(); ++lineNumIt) {
				cout << "   (line " << *lineNumIt << ") " << text[*lineNumIt - 1] << endl;
			}
		}
	} while (true);
	return 0;
}
