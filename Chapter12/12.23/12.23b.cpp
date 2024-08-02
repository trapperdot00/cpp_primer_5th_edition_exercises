#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
	string s = "Hello, ", s2 = "World!";
	s += s2;
	cout << s << endl;
	return 0;
}
