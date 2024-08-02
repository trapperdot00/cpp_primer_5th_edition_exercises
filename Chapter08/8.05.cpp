#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using std::ifstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char **argv) {
	for (char **p = argv + 1; p != argv + argc; ++p) {
		ifstream inFile(*p);
		if (inFile) {	// if inFile.good()
			vector<string> lines;
			for (string line; inFile >> line; lines.push_back(line)) {
				cout << line << endl;
			}
		}
	}
	return 0;
}
