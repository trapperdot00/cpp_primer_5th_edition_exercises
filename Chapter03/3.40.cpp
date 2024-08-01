#include <cstring>	// strcpy, strcmp, strcat, strlen functions
#include <iostream>

using std::cout;
using std::endl;
using std::strcpy;
using std::strcmp;
using std::strlen;
using std::strcat;

int main() {
	char ca1[] = "asdfghjk";
	char ca2[9] = "qwertyui";

	char ca3[17];
	
	strcpy(ca3, ca1);
	cout << "ca3 after strcpy(): " << ca3 << endl;

	strcat(ca3, ca2);
	cout << "ca3 after strcat(): " << ca3 << endl;
	
	cout << "length of ca3: " << strlen(ca3) << endl;

	return 0;
}
