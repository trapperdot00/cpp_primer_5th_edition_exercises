#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

void print(vector<int>::const_iterator start, vector<int>::const_iterator end) {
	if (start != end) {
		cout << *start << " ";
		return print(start+1, end);
	}
	cout << endl;
	return;
}

int main() {
	vector<int> ivec;
	for (int i = 0; i != 10; ++i)
		ivec.push_back(i);
	print(ivec.begin(), ivec.end());
	return 0;
}
