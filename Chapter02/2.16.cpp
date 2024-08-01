#include <iostream>

int main() {
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;

	r2 = 3.14159; // assigns 3.14159 to d
	r2 = r1;	// assigns 0 (value of i) to d
	i = r2;	// assigns truncated value of d to i
	r1 = d;	// assigns truncated valud of d to i
	return 0;
}
