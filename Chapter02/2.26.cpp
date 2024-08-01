#include <iostream>

int main() {
	// const int buf; // invalid: const not initialized
	int cnt = 0;	// legal
	const int sz = cnt;	// legal: const initialized at runtime
	++cnt;	// legal: non-const incremented
	// ++sz;	// invalid: const can't be incremented
	return 0;
}
