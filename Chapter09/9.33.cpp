#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
	vector<int>::iterator begin = ivec.begin();
	while (begin != ivec.end()) {
		++begin;
		ivec.insert(begin, 42); // error: insert invalidates every iterator to elements after the insertion
		++begin;
	}
	for (const int &i : ivec)
		cout << i << ' ';
	cout << endl;
	return 0;
}
