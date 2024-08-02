#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> ivec{1};
	cout << ivec.at(0) << ' ' << ivec[0] << ' ' << ivec.front() << ' ' << *ivec.begin() << endl;

	return 0;
}
