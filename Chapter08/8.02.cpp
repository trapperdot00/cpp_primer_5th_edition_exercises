#include <iostream>
#include <string>

std::istream &read(std::istream &is) {
	std::string s;
	while (is >> s)
		std::cout << s << std::endl;
	//is.clear();	you can use this also
	is.clear(is.rdstate() & ~is.failbit & ~is.badbit & ~is.eofbit);
	return is;
}

int main() {
	read(std::cin);
	if (std::cin)
		std::cout << "nice" << std::endl;
	return 0;
}
