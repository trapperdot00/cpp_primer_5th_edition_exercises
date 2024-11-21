#include "TextQuery.h"
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;

void runQueries(ifstream &in) {
	TextQuery tq(in);
	while (true) {
		cout << "enter word to look for, or q to quit ";
		string s;
		if (!(cin >> s) || s == "q") break;
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
