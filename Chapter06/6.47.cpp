#include <vector>
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::vector;

void print(vector<int>::const_iterator start, vector<int>::const_iterator end) {
	#ifndef NDEBUG
	cout << __func__ << " : size of vector: " << end - start << endl;
	#endif
	if (start != end) {
		cout << *start << " ";
		return print(start+1, end);
	}
	#ifdef NDEBUG
	cout << endl;
	#endif
	return;
}

int main() {
	#ifndef NDEBUG
	cout << __FILE__ << " - compiled on " << __DATE__ << " at " << __TIME__ << endl;
	#endif
	vector<int> ivec;
	for (int i = 0; i != 10; ++i)
		ivec.push_back(i);
	print(ivec.begin(), ivec.end());
	return 0;
}
