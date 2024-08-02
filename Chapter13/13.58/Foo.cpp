#include "Foo.h"

Foo::Foo(const Foo &f) : data(f.data) {}

Foo &Foo::operator=(const Foo &rhs) & {
	data = rhs.data;
	return *this;
}

Foo &Foo::operator=(Foo &&rhs) & {
	data = std::move(rhs.data);
	return *this;
}

Foo Foo::sorted() && {
	std::cout << "&&" << std::endl;
	std::sort(data.begin(), data.end());
	return *this;
}
