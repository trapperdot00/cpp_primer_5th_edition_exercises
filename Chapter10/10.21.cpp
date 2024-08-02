#include <iostream>

int main() {
	int i = 15;
	auto l = [&i]() -> bool { if (i) { --i; return false; }  else { return true; } };
	// ugly mess
	auto doing = [l, &i]() { while (!l()) { std::cout << i << std::endl;	} };
	doing();
	return 0;
}
