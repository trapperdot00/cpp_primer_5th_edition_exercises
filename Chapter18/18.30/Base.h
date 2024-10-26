#ifndef BASE_H
#define BASE_H

#include "Class.h"

class Base : public Class {
public:
	Base() : Class() {}
	Base(int i) : Class(), value(i) {}
	Base(const Base &b) : Class(b), value(b.value) {}
private:
	int value;
};

#endif
