#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
	std::istream_iterator<int> in(std::cin), eof;
	std::vector<int> vec(in, eof);
	std::ostream_iterator<int> out(std::cout, " ");
	std::copy(vec.crbegin(), vec.crend(), out);
	std::cout << std::endl;
	return 0;
}
