#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
	vector<int> ivec1;
	cout << "First vector" << endl;
	for (int num = 0; ivec1.size() != 8; ) {
		if (cin >> num) {
			ivec1.push_back(num);
		}
	}
	vector<int> ivec2;
	cout << "Second vector" << endl;
	for (int num = 0; ivec2.size() != 8; ) {
		if (cin >> num) {
			ivec2.push_back(num);
		}
	}
	cout << endl;
	for (const int &i : ivec1) {
		cout << i << " ";
	}
	cout << endl;
	for (const int &i : ivec2) {
		cout << i << " ";
	}
	cout << endl;
	/*
	vector<int>::const_iterator p1 = ivec1.begin(), p2 = ivec1.end();
	vector<int>::const_iterator p3 = ivec2.begin(), p4 = ivec2.end();
	while (p1 != p2 && p3 != p4 && *p1 == *p3) {
		++p1;
		++p3;
	}
	if (p1 == p2 && p3 == p4) {
		cout << "The two vectors don't differ" << endl;
	} else {
		cout << "The two vectors differ from each other" << endl;
	}
	*/
	if (ivec1 == ivec2) {
		cout << "The two vectors don't differ" << endl;
	} else {
		cout << "The two vectors differ from each other" << endl;
	}
}
