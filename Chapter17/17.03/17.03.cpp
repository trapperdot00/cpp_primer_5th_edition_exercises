#include "TextQuery.h"
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <set>

using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;
using std::get;
using std::set;

void runQueries(TextQuery &tq) {
	cout << "Enter word: ";
	for (string word; cin >> word; ) {
		TextQuery::Result ret = tq.query(word);
		cout << "Results for " << get<0>(ret) << ":\n";
		for (set<TextQuery::line_no>::const_iterator it = get<1>(ret)->cbegin();
			 it != get<1>(ret)->cend();
			 ++it) {
			cout << "\t(line " << *it + 1 << ") " << get<2>(ret)->operator[](*it) << "\n";
		}
		if (get<1>(ret)->empty())
			cout << "\tNot found" << endl;
		cout << "Enter word: ";
	}
}

int main() {
	string filename;
	cout << "Enter filename: ";
	if (!getline(cin, filename)) return -1;
	ifstream infile(filename);
	if (!infile.is_open()) return -2;
	TextQuery tq(infile);
	runQueries(tq);
	
	return 0;
}
