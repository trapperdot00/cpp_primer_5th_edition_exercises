#include "HasPtr.h"

#include <utility>

int main() {
	HasPtr a("the");
	HasPtr b("end");
	HasPtr c("!!!");

	a = b;
	c = std::move(b);

	return 0;
}
