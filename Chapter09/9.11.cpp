#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;



int main() {
	vector<int> ivec1;	// empty vector
	vector<int> ivec2(10);	// 10 elements with values 0
	vector<int> ivec3(10, 3);	// 10 elements with values 3
	vector<int> ivec4(ivec3.begin(), ivec3.end());	// elements of ivec3 from the iterator range
	vector<int> ivec5 = ivec4;	// copy of ivec4
	vector<int> ivec6 = {1, 2, 3, 4, 5};	// values 1, 2, 3, 4, 5 list initialization
	
	cout << "ivec1 size: " << ivec1.size() << " elements: ";
	for (const int& i : ivec1)
		cout << i << " ";
	cout << "\nivec2 size: " << ivec2.size() << " elements: ";
	for (const int& i : ivec2)
		cout << i << " ";
	cout << "\nivec3 size: " << ivec3.size() << " elements: ";
	for (const int& i : ivec3)
		cout << i << " ";
	cout << "\nivec4 size: " << ivec4.size() << " elements: ";
	for (const int& i : ivec4)
		cout << i << " ";
	cout << "\nivec5 size: " << ivec5.size() << " elements: ";
	for (const int& i : ivec5)
		cout << i << " ";
	cout << "\nivec6 size: " << ivec6.size() << " elements: ";
	for (const int& i : ivec6)
		cout << i << " ";
	cout << endl;
	return 0;
}
