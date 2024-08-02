#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main() {
	list<int> li = {1,2,3,4,5};
	vector<int> vi = {1,2,3,4,5};
	vector<int> liCp(li.begin(), li.end());
	if (liCp == vi)
		cout << "The elements are equal" << endl;
	else
		cout << "The elements differ" << endl;
	return 0;
}
