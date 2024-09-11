#include "Readme.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <sstream>

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::size_t;
using std::string;
using std::istringstream;

int main(int argc, char **argv) {
	if (argc < 4) {
		std::cerr << "usage: command + outfile + chapter + exercisecount" << std::endl;
		return -1;
	}
	ofstream outfile(argv[1]);
	istringstream stream(argv[2]);
	size_t chapter, excnt;
	stream >> chapter;
	stream.clear();
	stream.str(argv[3]);
	stream >> excnt;
	Readme mdgen(chapter, excnt);
	outfile << mdgen.generate();
	return 0;
}
