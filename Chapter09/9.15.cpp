#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<int> ivec1{1,2,3,4,5}, ivec2{1,2,3,4,5};
	if (ivec1 == ivec2)
		cout << "The two vectors are equal" << endl;
	else
		cout << "The two vectors aren't equal" << endl;
	return 0;
}
