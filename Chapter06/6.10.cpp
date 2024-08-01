#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void swap(int* i, int* j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

int main() {
	int a, b;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	swap(&a, &b);
	cout << "a: " << a << " b: " << b << endl;
	return 0;
}
