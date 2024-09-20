#include "RootReadme.h"

#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>

using std::cerr;
using std::endl;
using std::size_t;
using std::ofstream;
using std::stoull;

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "usage: command + chaptercount" << endl;
		return -1;
	}
	size_t chapter = stoull(argv[1]);
	RootReadme rr(chapter);
	ofstream outfile(rr.filename, ofstream::app);
	outfile << rr.generate();
	return 0;
}
