#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::cout;
using std::endl;

bool compare(list<int> liint, vector<int> vecint) {
	if (liint.size() != vecint.size())
		return false;
	list<int>::const_iterator iter1 = liint.cbegin();
	vector<int>::const_iterator iter2 = vecint.cbegin();
	while (iter1 != liint.cend() && iter2 != vecint.end()) {
		if (*iter1 != *iter2)
			return false;
		++iter1;
		++iter2;
	}
	return true;
}

int main() {
	list<int> li = {1,2,3,4,5};
	vector<int> vi = {1,2,3,4,6};
	if (compare(li, vi))
		cout << "The elements are equal" << endl;
	else
		cout << "The elements differ" << endl;
	return 0;
}
