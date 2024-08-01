#include <iostream>
#include <iterator>
#include <cstddef>	// size_t and ptrdiff_t

using std::end;
using std::begin;
using std::cout;
using std::endl;
using std::cin;

int main() {
	constexpr size_t sz = 8;
	int arr1[sz] = {};
	int *p1 = begin(arr1), *p2 = end(arr1);
	int num;
	cout << "First array" << endl;
	while (p1 != p2) {
		if (cin >> num) {
			*p1 = num;
			++p1;
		}
	}
	cout << "Second array" << endl;
	int arr2[sz] = {};
	p1 = begin(arr2);
	p2 = end(arr2);
	while (p1 != p2) {
		if (cin >> num) {
			*p1 = num;
			++p1;
		}
	}
	cout << endl;
	for (const int &i : arr1) {
		cout << i << " ";
	}
	cout << endl;
	for (const int &i : arr2) {
		cout << i << " ";
	}
	cout << endl;
	
	p1 = begin(arr1);
	p2 = begin(arr2);
	while (p1 != end(arr1) && p2 != end(arr2) && *p1 == *p2) {
		++p1;
		++p2;
	}
	if (p1 == end(arr1) && p2 == end(arr2)) {
		cout << "The two arrays don't differ" << endl;
	} else {
		cout << "The two arrays differ from each other" << endl;
	}
	return 0;
}

