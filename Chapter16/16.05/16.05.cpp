#include "print.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {
	int ia1[6] = {4,3,2,1,0,-1};
	int ia2[12] = {-6,-5,-4,-3,-2,-1,1,2,3,4,5,6};
	
	print(ia1);
	cout << endl;
	print(ia2);

	return 0;
}
