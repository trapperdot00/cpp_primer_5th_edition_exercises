#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>

class HasPtr {
	friend void swap(HasPtr &, HasPtr &);
public:
	HasPtr(const std::string & = std::string());
	HasPtr(const HasPtr &);
	HasPtr &operator=(HasPtr);
	~HasPtr();
private:
	std::string *ps;
	int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
	std::cout << "swap(HasPtr &, HasPtr &);" << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

#endif
