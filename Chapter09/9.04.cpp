#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

bool presentIn(vector<int>::const_iterator begIter, vector<int>::const_iterator endIter, int seek) {
	while (begIter != endIter) {
		if (*begIter == seek)
			return true;
		++begIter;
	}
	return false;
}

int main() {
	vector<int> ivec;
	for (int val = 0; val != 10; ++val)
		ivec.push_back(val * 2);
	cout << "Enter value to find in vector: ";
	int findVal;
	cin >> findVal;
	cout << "Value is " << (presentIn(ivec.cbegin(), ivec.cend(), findVal) ? "" : "not ") << "present in the vector" << endl;
	return 0;
}
