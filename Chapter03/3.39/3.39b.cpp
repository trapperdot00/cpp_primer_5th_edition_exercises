#include <iostream>
#include <cstring>

using std::strcmp;
using std::cout;
using std::endl;

int main() {
	const char ca1[9] = "asdfghjk";	// size is 9, because string literals contain the null-terminator
	const char ca2[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', '\0'};	// explicit null, size is 9
	
	if (strcmp(ca1, ca2) == 0) {	// strcmp returns 0 if C-strings are equal
		cout << "The two strings are equal." << endl;
	} else if (strcmp(ca1, ca2) > 0) {	// returns a positive value if the first string is larger
		cout << "The first string is larger than the second one." << endl;
	} else {	// returns a negative value if the second string is larger
		cout << "The second string is larger than the first one." << endl;
	}
	return 0;
}
