#include <list>
#include <forward_list>
#include <iostream>

using std::cout;
using std::endl;
using std::list;
using std::forward_list;

// remove even elements, duplicate odd ones
// can cache end iterator in lists and forward_lists, in functions that change or remove elements
// from these containers, but not with deque, string or vector!!!
// don't need to store the returned iterators from insert, or erase, because iterators are not
// invalidated after inserting elements or deleting elements from the lists (only for the deleted items)
void func(forward_list<int> &c) {
	forward_list<int>::iterator prev = c.before_begin(), iter = c.begin(), end = c.end();
	while (iter != end) {
		if (*iter % 2) {
			c.insert_after(prev, *iter);
			prev = iter;
			++iter;
		} else {
			iter = c.erase_after(prev);
		}
	}
}
void func(list<int> &c) {
	list<int>::iterator iter = c.begin(), end = c.end();
	while (iter != end) {
		if (*iter % 2) {
			c.insert(iter, *iter);
			++iter;
		} else {
			iter = c.erase(iter);
		}
	}
}

void init(forward_list<int> &c) {
	for (int i = 9; i != -1; --i)
		c.push_front(i);
}
void init(list<int> &c) {
	for (int i = 0; i != 10; ++i)
		c.push_back(i);
}

std::ostream &print(std::ostream &os, const forward_list<int> &c) {
	for (const int &i : c)
		os << i << ' ';
	return os;
}
std::ostream &print(std::ostream &os, const list<int> &c) {
	for (const int &i : c)
		os << i << ' ';
	return os;
}

int main() {
	forward_list<int> fli;
	list<int> li;
	init(fli);
	init(li);
	print(cout, fli) << '\n';
	print(cout, li) << '\n';
	func(fli);
	func(li);
	print(cout, fli) << '\n';
	print(cout, li) << endl;

	return 0;
}
