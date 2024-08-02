#include <iostream>

struct X{
	// DEFAULT CONSTRUCTOR
	X() { std::cout << "X()" << std::endl; }
	
	// COPY CONSTRUCTOR
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	
	// COPY-ASSIGNMENT OPERATOR
	X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }

	// DESTRUCTOR
	~X() { std::cout << "~X()" << std::endl; }
};
