#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

int main() {
	std::ifstream inFile("../page.txt");
	std::istream_iterator<std::string> inIter(inFile), err;
	
	// copy the iterator range of the two istream iterators (reading until eof or error) into vector
	std::vector<std::string> v1(inIter, err);

	// create an ostream iterator that prints strings, with cout and appending a newline after each print
	std::ostream_iterator<std::string> outIter(std::cout, " ");

	// copy the vector's elements to the iter, printing it out
	std::copy(v1.cbegin(), v1.cend(), outIter);
	return 0;
}
