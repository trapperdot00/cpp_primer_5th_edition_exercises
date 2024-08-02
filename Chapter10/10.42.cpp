#include <list>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

int main() {
	std::istream_iterator<std::string> in(std::cin), eof;
	std::list<std::string> words(in, eof);
	words.sort();
	words.unique();
	std::ostream_iterator<std::string> out(std::cout, " ");
	std::copy(words.cbegin(), words.cend(), out);
	std::cout << '\n' << words.size() << std::endl;
	return 0;
}
