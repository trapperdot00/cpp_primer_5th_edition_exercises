#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> v1 = {0, 1, 1, 2, 3, 5, 8};
	vector<int> v2 = {0, 1, 1, 2};
	bool status;
	vector<int>::size_type idx = 0;
	while  (idx != v1.size() && idx != v2.size() && v1[idx] == v2[idx]) {
		++idx;
	}
	if (idx == v1.size() || idx == v2.size()) {
		status = true;
	} else {
		status = false;
	}
	cout << status << endl;
	return 0;
}
