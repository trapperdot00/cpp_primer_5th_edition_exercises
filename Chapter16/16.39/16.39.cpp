#include "compare.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
	int result;

	// Compare the two strings
	result = compare<string>("hello", "bye");
	cout << (result == 0 ? "The strings have equal values" :
			result == 1 ? "The first string is larger than the second" :
		    "The second string is larger than the first") << endl;

	// Compare the pointer values
	result = compare<const char *>("hello", "bye");	// explicit array to pointer conversion:
													// function parameters are references, won't
													// implicitly convert it to a pointer
	cout << (result == 0 ? "The pointers point to the same element" :
			result == 1 ? "The first pointer holds an address larger than the second" :
			"The second pointer holds an address larger than the first") << endl;
	return 0;
}
