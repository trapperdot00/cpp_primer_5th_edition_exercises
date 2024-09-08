#include "Screen.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	Screen<2,4> s1('#'), s2('X'), s3('-');
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	Screen<3,5> userS;
	cout << "Enter contents for Screen of size 5x3 :" << endl;
	cin >> userS;
	cout << userS << endl;
	return 0;
}
