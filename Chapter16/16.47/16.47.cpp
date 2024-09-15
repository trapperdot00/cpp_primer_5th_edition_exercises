#include "flip.h"
#include <iostream>
#include <functional>
#include <string>

template <typename T>
void printLarger(const T &i, const T &j) {
	std::cout << "Larger: " << (std::greater<T>()(i, j) ? i : j) << std::endl;
}

template <typename T>
void printSum(const T &i, const T &j) {
	std::cout << "Sum: " << i + j << std::endl;
}

template <typename T>
void changer(T &changeable, T localcopy) {
	std::cout << "changer(): " << ++changeable << " " << ++localcopy << std::endl;
}

void rval_lval_changer(int &lval, int &&rval) {
	std::cout << "rval_lval_changer(): " << ++lval << " " << ++rval << std::endl;
}

int main() {
	int a = 3, b = 4;
	std::string s1 = "Basalt", s2 = "Apple";

	flip(printLarger<int>, 1, 2);
	flip(printLarger<int>, b, a);
	flip(printLarger<std::string>, std::string("Basalt"), std::string("Apple"));
	flip(printLarger<std::string>, s2, s1);

	flip(printSum<int>, 1, 2);
	flip(printSum<int>, b, a);
	flip(printSum<std::string>, std::string("Basalt"), std::string("Apple"));
	flip(printSum<std::string>, s2, s1);

	int i = 15;
	std::cout << "\ni: " << i << std::endl;
	flip(changer<int>, 9, i);		// i will change, reference in changer binds to this
	std::cout << "i: " << i << std::endl;
	flip(rval_lval_changer, 9, i);	// i will change again
	std::cout << "i: " << i << std::endl;

	// flip(rval_lval_changer, a, b); 	illegal

	return 0;
}
