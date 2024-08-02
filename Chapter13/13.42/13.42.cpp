#include "StrVec.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::ifstream;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
	if (argc < 2) return -1;
	ifstream in(argv[1]);
	if (!in.is_open()) return -2;
	cout << "Loading file..." << endl;
	TextQuery tq(in);
	while (true) {
		string search;
		cout << "Enter word to look for, or q to quit: ";
		if (!(cin >> search) || search == "q") {
			   cout << "Closing file..." << endl;
				break;
		}
		print(cout, tq.query(search)) << endl;
	}
	return 0;
}
