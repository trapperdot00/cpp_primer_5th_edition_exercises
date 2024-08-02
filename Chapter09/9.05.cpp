#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

vector<int>::const_iterator presentIn(vector<int>::const_iterator begIter, vector<int>::const_iterator endIter, int seek) {
	while (begIter != endIter) {
		if (*begIter == seek)
			return begIter;
		++begIter;
	}
	return endIter;
}

int main() {
	vector<int> ivec;
	for (int val = 0; val != 10; ++val)
		ivec.push_back(val * 2);
	cout << "Enter value to find in vector: ";
	int findVal;
	cin >> findVal;
	vector<int>::const_iterator found = presentIn(ivec.cbegin(), ivec.cend(), findVal);
	if (found != ivec.cend())
		cout << "Value: " << *found << endl;
	else
		cout << "Value is not found" << endl;
	return 0;
}
