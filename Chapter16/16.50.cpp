template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);

#include <iostream>

template <typename T> void f(T) {
	std::cout << "f(T)" << std::endl;
}
template <typename T> void f(const T*) {
	std::cout << "f(const T*)" << std::endl;
}
template <typename T> void g(T) {
	std::cout << "g(T)" << std::endl;
}
template <typename T> void g(T*) {
	std::cout << "g(T*)" << std::endl;
}

int main() {
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42);	g(p);	g(ci);	g(p2);
	f(42);	f(p);	f(ci);	f(p2);
	return 0;
}
