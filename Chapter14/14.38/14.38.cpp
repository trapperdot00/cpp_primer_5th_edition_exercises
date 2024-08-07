#include "Bound.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstddef>

using std::size_t;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::cerr;

int main(int argc, char **argv) {
	if (argc < 2) {
		cerr << "usage: command + input file" << endl;
		return -1;
	}
	ifstream infile(argv[1]);
	if (!infile.is_open()) {
		cerr << "input file doesn't exist" << endl;
		return -2;
	}

	string::size_type maxSize = 10;
	Bound obj(maxSize);
	size_t wordCount = 0;
	for (string word; infile >> word; ) {
		if (obj(word))
			++wordCount;
	}
	cout << wordCount << " words have a size less than or equal to " << maxSize << endl;
	return 0;
}
