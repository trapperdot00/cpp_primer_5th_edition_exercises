#include "find_val.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <array>
#include <cstddef>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;
using std::array;
using std::size_t;

int main() {
	vector<int> ivec = {1,2,3,4,5,6};

	cout << "vector:" << endl;
	// Search for values 0 to 9
	for (int search_val = 0; search_val != 10; ++search_val) {
		vector<int>::const_iterator vret = find_val(ivec.cbegin(), ivec.cend(), search_val);
		cout << search_val;
		if (vret == ivec.cend())
			cout << " not";
		cout << " found" << endl;
	}
	cout << "\nlist:" << endl;

	list<string> sli = {"hello", "hi", "hey", "okay"};
	array<string, 10> search_words = {"goodbye", "bye", "hiya", "hi", "hey", "wow", "okay", "oh", "what", "hey"};
	// Search for values in the array
	for (size_t idx = 0; idx != 10; ++idx) {
		const string &current = search_words[idx];
		list<string>::const_iterator lret = find_val(sli.cbegin(), sli.cend(), current);
		cout << current;
		if (lret == sli.cend())
			cout << " not";
		cout << " found" << endl;
	}
	return 0;
}
