#include <iostream>

int main() {
	int i = 43;
	void *p = &i;	// legal: pointers of type void can point to any type
	//	long *lp = &i;	// illegal: type of pointer must match the object that it points to
	return 0;
}
