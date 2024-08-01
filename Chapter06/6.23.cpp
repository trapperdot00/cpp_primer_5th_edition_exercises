#include <iostream>
#include <iterator>

using std::begin;
using std::end;
using std::cout;
using std::endl;

void print(const char *cp) {
	if (cp)
		while (*cp)
			cout << *cp++;
}

void print(const int *beg, const int *end) {
	while (beg != end)
		cout << *beg++ << endl;
}

void print(const int *ia, size_t size) {
	for (size_t i = 0; i != size; ++i) {
		cout << ia[i] << endl;
	}
}

void print(int (&arr)[2]) {
	for (int elem : arr) {
		cout << elem << endl;
	}
}

int main() {
	int i = 0, j[2] = {0, 1};

	print(&i, &i+1);
	print(&i, 1);

	print(begin(j), end(j));
	print(j, 2);
	print(j);

	return 0;
}
