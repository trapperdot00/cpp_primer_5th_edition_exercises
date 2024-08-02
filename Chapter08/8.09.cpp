#include <iostream>
#include <string>
#include <sstream>

std::istream &read(std::istream &is) {
	std::string s;
	while (is >> s)
		std::cout << s << std::endl;
	//is.clear();	you can use this also
	is.clear(is.rdstate() & ~is.failbit & ~is.badbit & ~is.eofbit);
	return is;
}

int main() {
	std::string s = "aaa a a a aa abb abb ab bb abb b b\nccc cc c cc c\nccc  cc cccccc d";
	std::istringstream input(s);
	read(input);
	return 0;
}
