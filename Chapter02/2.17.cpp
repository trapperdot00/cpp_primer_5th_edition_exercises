#include <iostream>

int main() {
	int i, &ri = i;
	i = 5;
	ri = 10;
	std::cout << i << " " << ri << std::endl;	//	will print 10 10
	return 0;
}