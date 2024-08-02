#include <memory>
#include <vector>
#include <iostream>

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

shared_ptr<vector<int>> factory() {
	return make_shared<vector<int>>();
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
	shared_ptr<vector<int>> heapVec = factory();
	read(cin, *heapVec);
	print(cout, *heapVec) << endl;;
	return 0;
}
