#include "ReadString.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::for_each;

int main() {
	vector<string> svec;
	ReadString obj;
	// read into the vector
	for (string line; !(line = obj()).empty(); svec.push_back(line)) ; // header does all the work
	// printing each element
	for_each(svec.cbegin(), svec.cend(), [](const string &s){ cout << s << endl; });
	return 0;
}
