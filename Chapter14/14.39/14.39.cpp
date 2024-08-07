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

	string::size_type maxSize = 9;
	Bound obj(maxSize);
	size_t low = 0, high = 0;
	for (string word; infile >> word; ) {
		if (obj(word))
			++low;
		else
			++high;
	}
	cout << low << " words have a size less than or equal to " << maxSize << '\n' << 
		   high << " words have a size higher than " << maxSize << endl;
	return 0;
}
