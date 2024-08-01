#include <iostream>

int main() {
	int i = 0;
	// double* dp = &i; // illegal: types don't match
	// int *ip = i;	// illegal: pointer can't be initialized to a numeric value, only a memory address
	int *p = &i;	// legal
	return 0;
}
