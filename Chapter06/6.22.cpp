#include <iostream>

using std::cout;
using std::endl;

void swapP(int **p1, int **p2) {
	int *temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


// int not read-only
void swapPs(int *&p1, int *&p2) {
	int *temp = p1;
	p1 = p2;
	p2 = temp;
}

int main() {
	int a = 1, b = 2;
	int *p = &a, *k = &b;
	cout << "*p: " << *p << " *k: " << *k << endl;
	swapP(&p, &k);
	cout << "*p: " << *p << " *k: " << *k << endl;

	return 0;
}
