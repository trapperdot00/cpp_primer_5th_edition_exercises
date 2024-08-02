#include "TextQuery.h"
#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
using std::string;

void runQueries(ifstream &infile) {
	TextQuery tq(infile);
	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) return -1;
	std::ifstream in(argv[1]);
	runQueries(in);
	return 0;
}
