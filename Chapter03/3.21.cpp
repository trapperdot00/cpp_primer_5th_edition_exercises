#include <vector>
#include <iterator>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<string> v6{10};
	vector<string> v7{10, "hi"};
	
	unsigned size = 0;
	cout << "v1	size: ";
	for (vector<int>::const_iterator it = v1.cbegin(); it != v1.cend(); ++it) {
		++size;
	}
	cout << size << "\nelements: ";
	for (vector<int>::const_iterator it = v1.cbegin(); it != v1.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	size = 0;

	cout << "\nv2 size: ";
	for (vector<int>::const_iterator it = v2.cbegin(); it != v2.cend(); ++it) {
		++size;
	}
	cout << size << "\nelements: ";
	for (vector<int>::const_iterator it = v2.cbegin(); it != v2.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	size = 0;
	
	cout << "\nv3 size: ";
	for (vector<int>::const_iterator it = v3.cbegin(); it != v3.cend(); ++it) {
		++size;
	}
	cout << size << "\nelements: ";
	for (vector<int>::const_iterator it = v3.cbegin(); it != v3.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	size = 0;
	
	cout << "\nv4 size: ";
	for (vector<int>::const_iterator it = v4.cbegin(); it != v4.cend(); ++it) {
		++size;
	}
	cout << size << "\nelements: ";
	for (vector<int>::const_iterator it = v4.cbegin(); it != v4.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	size = 0;
	
	cout << "\nv5 size: ";
	for (vector<int>::const_iterator it = v5.cbegin(); it != v5.cend(); ++it) {
		++size;
	}
	cout << size << "\nelements: ";
	for (vector<int>::const_iterator it = v5.cbegin(); it != v5.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	size = 0;
	cout << "\nv6 size: ";
	for (vector<string>::const_iterator it = v6.cbegin(); it != v6.cend(); ++it) {
		++size;
	}
	cout << size << "\nelements: ";
	for (vector<string>::const_iterator it = v6.cbegin(); it != v6.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	size = 0;
	cout << "\nv7 size: ";
	for (vector<string>::const_iterator it = v7.cbegin(); it != v7.cend(); ++it) {
		++size;
	}
	cout << size << "\nelements: ";
	for (vector<string>::const_iterator it = v7.cbegin(); it != v7.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
	
