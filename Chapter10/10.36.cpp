#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

int main() {
	std::istream_iterator<int> in(std::cin), eof;
	std::list<int> lst(in, eof);
	std::list<int>::const_reverse_iterator iter = std::find(lst.crbegin(), lst.crend(), 0);
	std::cout << *iter << ' ';
	return 0;
}
