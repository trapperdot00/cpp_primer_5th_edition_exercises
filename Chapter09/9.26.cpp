#include <vector>
#include <list>
#include <iostream>
#include <iterator>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	vector<int> ivec(begin(ia), end(ia));
	list<int> li(ivec.begin(), ivec.end());
	cout << "ia:\t";
	for (const int &i : ia)
		cout << i << ' ';
	cout << "\nivec:\t";
	for (const int &i : ivec)
		cout << i << ' ';
	cout << "\nli:\t";
	for (const int &i : li)
		cout << i << ' ';

	vector<int>::iterator iveciter = ivec.begin();
	while (iveciter != ivec.end()) {
		if (*iveciter % 2 == 0) {
			iveciter = ivec.erase(iveciter);
		} else {
			++iveciter;
		}
	}

	list<int>::iterator liiter = li.begin();
	while (liiter != li.end()) {
		if (*liiter % 2) {
			liiter = li.erase(liiter);
		} else {
			++liiter;
		}
	}

	cout << "\n\nivec:\t";
	for (const int &i : ivec)
		cout << i << ' ';
	cout << "\nli:\t";
	for (const int &i : li)
		cout << i << ' ';
	cout << endl;
	return 0;
}
