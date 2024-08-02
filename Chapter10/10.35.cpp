#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::istream_iterator<int> in(std::cin), eof;
	std::vector<int> vec(in, eof);
	std::vector<int>::const_iterator iter1 = vec.cbegin() + vec.size() - 1;
	for (unsigned shift = 0; shift != vec.size(); ++shift) {
		std::cout << *iter1-- << ' ';
	}
	std::cout << std::endl;
	return 0;
}
