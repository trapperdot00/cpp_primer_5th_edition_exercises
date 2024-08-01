#include <initializer_list>
#include <iostream>

using std::initializer_list;
using std::cout;
using std::endl;

int sum(initializer_list<int> li) {
	int ret = 0;
	for (const int &i : li)
		ret += i;
	return ret;
}

int main() {
	cout << sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;
	return 0;
}
