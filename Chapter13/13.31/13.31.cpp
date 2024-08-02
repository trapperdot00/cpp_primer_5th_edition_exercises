#include <vector>
#include "HasPtr.h"
#include <algorithm>
#include <iterator>

using std::back_inserter;
using std::ostream_iterator;
using std::copy;
using std::sort;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

int main() {
	vector<HasPtr> vec;
	for (string temp; getline(cin, temp); vec.push_back(HasPtr(temp))) ;
	for (const HasPtr &p : vec) {
		print(cout, p) << endl;
	}
	sort(vec.begin(), vec.end());
	for (const HasPtr &p : vec) {
		print(cout, p) << endl;
	}
	return 0;
}
