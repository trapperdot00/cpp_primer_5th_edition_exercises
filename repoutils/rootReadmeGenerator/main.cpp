#include "RootReadme.h"
#include <cstdlib>
#include <fstream>

int main(int argc, char *argv[]) {
	if (argc < 2) return -1;
	RootReadme rr(atoi(argv[1]));
	std::ofstream out("README.md", std::ofstream::app);
	out << rr.generate();
	return 0;
}
