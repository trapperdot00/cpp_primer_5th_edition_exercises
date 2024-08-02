#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using std::string;
using std::vector;
using std::istringstream;
using std::cout;
using std::ifstream;
using std::endl;

int main(int argc, char **argv) {
	if (argc < 2) return -1;
	ifstream inputFile(argv[1]);
	if (inputFile.fail()) return -1;
	vector<string> lines;
	for (string line; getline(inputFile, line); lines.push_back(line)) ; // empty body: header does all the work
	for (const string &line : lines ) {
		istringstream istr(line);
		for (string elem; istr >> elem; cout << elem << ' ') ;	// same
		cout << endl;
	}
	return 0;
}
