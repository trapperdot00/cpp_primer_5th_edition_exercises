#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

int main() {
	std::vector<int> vec{9,8,7,6,5,4,3,2,1,0};
	std::list<int> lst;
	std::copy(vec.crbegin() + 3, vec.crbegin() + 8, std::back_inserter(lst));
	std::ostream_iterator<int> out(std::cout, " ");
	std::for_each(lst.cbegin(), lst.cend(), [&out](int i) { out = i; });
	std::cout << std::endl;
	return 0;
}
