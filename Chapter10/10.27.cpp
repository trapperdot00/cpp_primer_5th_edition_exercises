#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <functional>

std::ostream &print(std::ostream &os, int val, char sep) {
	os << val << sep;
	return os;
}

int main() {
	std::vector<int> vec{1,1,2,3,2,2,5,7,7,2,6,9,2,1,4,8,0}, vecCpy;
	std::copy(vec.cbegin(), vec.cend(), std::back_inserter(vecCpy));
	std::sort(vecCpy.begin(), vecCpy.end());
	std::list<int> lst;
	std::unique_copy(vecCpy.cbegin(), vecCpy.cend(), std::back_inserter(lst));
	std::for_each(vecCpy.cbegin(), vecCpy.cend(), std::bind(print, std::ref(std::cout), std::placeholders::_1, ' '));
	std::cout << "\nSize of vector: " << vecCpy.size() << std::endl;
	std::for_each(lst.cbegin(), lst.cend(), [](int val) { print(std::cout, val, ' '); });
	std::cout << "\nSize of list: " << lst.size() << std::endl;

	return 0;
}
