// Example program that uses our function template to get iterators
// to an array's first and one past the last element to get a
// valid iterator range, that allows us to print the whole array

#include "array_iter.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	const int ia[10] = {0,1,2,3,4,5,6,7,8,9};
	for (const int *p = arr_begin(ia); p != arr_end(ia); ++p) {
		cout << *p << " ";
	}
	cout << endl;
	return 0;
}
