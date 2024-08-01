#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

// using int_array = int[4];
typedef int int_array[4];

int main() {
	int ia[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	for (const int_array *row = begin(ia); row != end(ia); ++row) {
		for (const int *col = begin(*row); col != end(*row); ++col) {
			cout << *col << " ";
		}
		cout << endl;
	}

	return 0;
}
