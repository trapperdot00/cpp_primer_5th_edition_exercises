#ifndef FOO_H
#define FOO_H

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

class Foo {
public:
	Foo(const Foo &);
	Foo &operator=(const Foo &) &;
	Foo &operator=(Foo &&) &;

	Foo sorted() &&;
	Foo sorted() const &;

private:
	std::vector<int> data;
};

#endif
