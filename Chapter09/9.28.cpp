#include <string>
#include <forward_list>
#include <iostream>

using std::string;
using std::forward_list;
using std::cout;
using std::endl;
using std::cin;

void findInsert(forward_list<string> &flst, const string &toFind, const string &toInsert) {
	bool found = false;
	forward_list<string>::iterator curr = flst.begin(), prev = flst.before_begin();
	while (curr != flst.end()) {
		if (*curr == toFind) {
			curr = flst.insert_after(curr, toInsert);
			prev = curr;
			++curr;
			found = true;
		} else {
			prev = curr;
			++curr;
		}
	}
	if (!found) {
		flst.insert_after(prev, toInsert);
	}
}

void print(forward_list<string>::const_iterator iter1, const forward_list<string>::const_iterator &iter2) {
	while (iter1 != iter2) {
		cout << *iter1++ << '\n';
	}
}

int main() {
	forward_list<string> lines;
	for (string line; getline(cin, line); lines.push_front(line)) ;
	print(lines.cbegin(), lines.cend());
	cout << endl;
	findInsert(lines, "amogus", "sus");
	print(lines.cbegin(), lines.cend());

	return 0;
}
