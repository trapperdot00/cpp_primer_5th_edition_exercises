#include <algorithm>
#include <iostream>
#include <vector>

using std::equal;
using std::cout;
using std::endl;
using std::vector;

int main() {
	vector<const char *> cvec{"string1", "string2"}, 
						 cvec2{"string1", "string1"};
	cout << equal(cvec.cbegin(), cvec.cend(), cvec2.cbegin()) << endl;
	return 0;
}

// compares address instead of the string literal, compares the two pointers, should be avoided!!!!
