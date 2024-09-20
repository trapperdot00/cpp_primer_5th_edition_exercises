#include "ChapterReadme.h"

#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>

using std::cerr;
using std::endl;
using std::ofstream;
using std::size_t;
using std::stoull;

int main(int argc, char *argv[]) {
	if (argc < 3) {
		cerr << "usage: command + chapter + exercisecount" << endl;
		return -1;
	}
	size_t chapter = stoull(argv[1]), excnt = stoull(argv[2]);
	ChapterReadme cr(chapter, excnt);
	ofstream outfile(cr.filename, ofstream::app);
	outfile << cr.generate();
	return 0;
}
