#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector<int> *factory() {
	return new vector<int>;
}

std::istream &read(std::istream &is, vector<int> &vec) {
	for (int temp; is >> temp; vec.push_back(temp)) ;
	return is;
}

std::ostream &print(std::ostream &os, vector<int> &vec) {
	for (const int &i : vec) { os << i << ' '; }
	return os;
}

int main() {
	vector<int> *heapVec = factory();
	read(cin, *heapVec);
	print(cout, *heapVec) << endl;
	return 0;
}
