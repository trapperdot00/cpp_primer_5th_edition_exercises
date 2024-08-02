#include <forward_list>
#include <iostream>

using std::forward_list;
using std::cout;
using std::endl;

void print(forward_list<int>::const_iterator iter1, const forward_list<int>::const_iterator &iter2) {
	while (iter1 != iter2)
		cout << *iter1++ << ' ';
	cout << endl;
}

void removeOdds(forward_list<int> &flist) {
	forward_list<int>::iterator curr = flist.begin(), prev = flist.before_begin();
	while (curr != flist.end()) {
		if (*curr % 2) {
			curr = flist.erase_after(prev);
		} else {
			prev = curr;
			++curr;
		}
	}
}

int main() {
	forward_list<int> fli = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print(fli.cbegin(), fli.cend());
	removeOdds(fli);
	print(fli.cbegin(), fli.cend());
	return 0;
}
