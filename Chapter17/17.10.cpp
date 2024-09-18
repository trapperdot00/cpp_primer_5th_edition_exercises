#include <bitset>
#include <vector>
#include <string>
#include <iostream>

using std::bitset;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
	vector<int> ivec{1,2,3,5,8,13,21};
	bitset<32> bitvec1("1000000010000100101110");
	cout << bitvec1 << endl;

	bitset<32> bitvec2;
	for (vector<int>::const_iterator it = ivec.cbegin(); it != ivec.cend(); ++it)
		bitvec2.set(*it, true);
	cout << bitvec2 << endl;

	return 0;
}
