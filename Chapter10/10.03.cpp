#include <numeric>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> ivec{0,1,2,3,4,5,6,7,8,9};
	cout << "Sum of elements in ivec: " << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;
	return 0;
}
