#include "HasPtr.h"

// VALUELIKE

HasPtr::HasPtr(const std::string &s) : ps(new std::string(s)), i(0) { }
HasPtr::HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) { }
HasPtr::HasPtr(HasPtr &&h) noexcept : ps(h.ps), i(h.i) { h.ps = nullptr; }
HasPtr &HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}
HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept {
	if (this != &rhs) {
		delete ps;
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
	}
	return *this;
}

HasPtr::~HasPtr() {
	delete ps;
}

std::ostream &print(std::ostream &os, const HasPtr &p) {
	os << *p.ps;
	return os;
}
