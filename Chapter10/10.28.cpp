#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

std::ostream &print(std::ostream &os, const std::vector<std::list<int>> &vec, char sep) {
	std::for_each(vec.cbegin(), vec.cend(),
		[&os, sep](const std::list<int> &l) -> void {
	   		std::for_each(l.cbegin(), l.cend(),
				[&os, sep](int i) -> void {
			   		os << i << sep; 
			});
			os << std::endl;
		}
	);
	return os;
}

int main() {
	std::vector<int> vec1;
	std::list<int> lst1, lst2, lst3;
	for (int i = 1; i != 10; ++i)
		vec1.push_back(i);
	std::copy(vec1.cbegin(), vec1.cend(), std::back_inserter(lst1));
	std::copy(vec1.cbegin(), vec1.cend(), std::inserter(lst2, lst2.begin()));	// inserter will work as a back_inserter on an empty container
	std::copy(vec1.cbegin(), vec1.cend(), std::front_inserter(lst3));
	std::vector<std::list<int>> collective{lst1, lst2, lst3};
	print(std::cout, collective, ' ');

	return 0;
}
