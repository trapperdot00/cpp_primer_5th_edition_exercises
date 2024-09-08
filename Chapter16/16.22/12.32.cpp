#include "TextQuery.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::transform;
using std::tolower;

void runQueries(ifstream &in) {
	TextQuery tq(in);
	while (true) {
		cout << "enter word to look for, or q to quit ";
		string s;
		if (!(cin >> s) || s == "q") break;
		transform(s.begin(), s.end(), s.begin(), [](char c){ return tolower(c); });
		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) return -1;
	string filename(argv[1]);
	ifstream in(filename);
	if (in.is_open())
		runQueries(in);
	return 0;
}
