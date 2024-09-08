#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template <typename Container>
std::ostream &print(std::ostream &os, const Container &c) {
	for (typename Container::const_iterator it = c.cbegin(); it != c.cend(); ++it)
		os << *it << ' ';
	return os;
}

int main() {
	vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
	print(cout, ivec) << endl;
	return 0;
}
