#include "HasPtr.h"

// VALUELIKE

HasPtr::HasPtr(const std::string &s) : ps(new std::string(s)), i(0) { }
HasPtr::HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) { }
HasPtr &HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}
HasPtr::~HasPtr() {
	delete ps;
}
